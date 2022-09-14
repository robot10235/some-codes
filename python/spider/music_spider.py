import requests
import os

'''
通过互联网发送http请求
get
获取网站页面资源
'''

# 伪造浏览器身份信息
# F12请求标头中user-agent的信息为浏览器身份
# 默认属性为python-requests，如果反爬虫会失败
# 浏览器信息格式类似字典

headers = {
    # 浏览器信息
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67',
    # 防盗链，如果只用user-agent还是403，需要仔细查找有无防盗链
    'Referer': 'http://kuwo.cn/',
    # 保证可靠性
    'Cookie': '_ga=GA1.2.120833336.1628403364; _gid=GA1.2.794305312.1628403364; _gat=1; Hm_lvt_cdb524f42f0ce19b169a8071123a4797=1628403933,1628404007,1628404043,1628404378; Hm_lpvt_cdb524f42f0ce19b169a8071123a4797=1628404378; kw_token=DJCILRARURE',
    # 防止跨越攻击的令牌
    'csrf': 'DJCILRARURE'
}

# response = requests.get('https://www.baidu.com', headers=hreaders)
# print(response.request.headers)

# 创建一个文件夹存储下载的信息
if not os.path.exists('./music/'):
    os.mkdir('./music/')

search_music = input("请输入歌曲/歌手：")
pn = 0

while True:
    pn += 1
    url = 'http://kuwo.cn/api/www/search/searchMusicBykeyWord?key={}&pn={}&rn=30&httpsStatus=1&reqId=b7ad4972-f819-11eb-9094-6bce15144991'.format(search_music, pn)
    response = requests.get(url, headers=headers).json()

    music_data = response['data']['list']

    music_name = []
    music_rid = []

    for music in music_data:
        music_name.append(music['name'])
        music_rid.append(music['rid'])

    for i in range(len(music_name)):
        print(i, music_name[i])

    # 选择下载
    while True:
        exit_flag = False
        Id = int(input("请输入想要下载音乐的编号（-1：退出，-2：下一页）："))
        if Id == -1:
            exit_flag = True
            break
        elif Id == -2:
            break
        try:
            music_api = 'http://kuwo.cn/url?format=mp3&rid={}&response=url&type=convert_url3&br=128kmp3&from=web&t=1628404071200&httpsStatus=1&reqId=c1a6f911-f811-11eb-b473-f16519e80bdb'.format(
                str(music_rid[Id]))
            with open('./music/' + music_name[Id] + '.mp3', 'wb') as f:
                music_play_url = requests.get(music_api, headers=headers).json()['url']
                # 音乐文件是二进制文件content
                music_download = requests.get(music_play_url, headers=headers).content
                f.write(music_download)
            print('下载成功：', music_name[Id])
        except IOError as e:
            print(e)

    if exit_flag:
        break
