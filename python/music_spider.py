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

hreaders = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67'
}

# response = requests.get('https://www.baidu.com', headers=hreaders)
# print(response.request.headers)

# 创建一个文件夹存储下载的信息
if not os.path.exists('./music/'):
    os.mkdir('./music/')

