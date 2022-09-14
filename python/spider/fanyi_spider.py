import requests
import json

class fanyi(object):

    def __init__(self, word):
        self.url = 'https://fanyi.baidu.com/v2transapi?from=zh&to=en'
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36 Edg/92.0.902.67',
            'Referer': 'https://fanyi.baidu.com/',
            'Cookie': 'BIDUPSID=E84008D9843AD52EF057C7014AE8FFFE; PSTM=1618713370; BAIDUID=E84008D9843AD52EF7E5E2A11EE2D05D:FG=1; __yjs_duid=1_87f931836cadbcc9a2b4087308fdad491618732390065; REALTIME_TRANS_SWITCH=1; FANYI_WORD_SWITCH=1; SOUND_SPD_SWITCH=1; SOUND_PREFER_SWITCH=1; HISTORY_SWITCH=1; BDSFRCVID_BFESS=qaIOJexroG0YGkTHWW2nFKmG9gKK0gOTDYLtOwXPsp3LGJLVgaTQEG0PtfO5jxF-QdMKogKK3gOTH4AF_2uxOjjg8UtVJeC6EG0Ptf8g0M5; H_BDCLCKID_SF_BFESS=JRKtoD0MtKvDqTrP-trf5DCShUFsb4oAB2Q-XPoO3KJZsnv2yhJRD4CzyUcxq4biWbRM2MbgylRM8P3y0bb2DUA1y4vpK-onLmTxoUJ25qAhj4nDqqQfXfPebPRiJ-b9Qg-J5lQ7tt5W8ncFbT7l5hKpbt-q0x-jLTnhVn0MBCK0HPonHjLaj63W3f; BAIDUID_BFESS=44F942A431A69E97E456ACBF7B28C148:FG=1; Hm_lvt_64ecd82404c51e03dc91cb9e8c025574=1628762949; Hm_lpvt_64ecd82404c51e03dc91cb9e8c025574=1628763546; __yjs_st=2_OTQxMjkxZGQ1MzUxMTE5YzkxNmVmNTg2Y2M4ZWZmMTlkNTk4ZjIxMTU2ODQ1Y2I5NDMyZjQwNGNiY2QxNzhkNDhhODE4YWU3YjMwMDMyN2I0N2IyNjFhM2FhMTQ2OWQxMjY3ZGZmYjc0NzFmMTYxYmVlOTc4NDI1YmEzNjU0NzRkMjAxYmFhZGNiYmEyZjBiNDAyMjk0ZGNkYjI2MzM4ZTE3ZWQ3MThlZDQ0MDc2OTI0MTNmNTI3OGViYjM2ZjU2YWU3ZjQ1MmE3NmFmNDI2YzU1NGM5YzVlYjhjMzIxYTQ1MzYwYjA0M2NlMTdjOGIwYmY1MzFkZTNlODVkMTU3NV83X2YyZWRhZmVj; ab_sr=1.0.1_NTI4N2M0YzE2MDBhYTdmNzAxNzc5YTFiNjg0NDk1N2ZmNjdmOTIxYmU5OGFjYjE5YTA1NDdhNjVjMzhmYjY5MzZjMTJmMjllYTRlMDE2OGM2NDg2MDhiMmQ5Zjc5NzBmYjUwZDEyYWJlMjVhZjIyMzUzNjdjN2Q0NDMxM2M1YjVkNzA1YjQ2M2NjNTdmYmI1ZGY3MzM2ZDkwZDZlNTM2ZA=='
        }
        self.data = {
            'from': 'zh',
            'to': 'en',
            'query': word,
            'transtype': 'translang',
            'simple_means_flag': '3',
            'sign': '31941.303092',
            'token': '5b8a674dac5a12580966be74e4cf0fc9',
            'domain': 'common'
        }

    def get_data(self):
        response = requests.post(self.url, data=self.data, headers=self.headers)
        return response.text

    def run(self):
        response = self.get_data()
        dic = json.loads(response)
        print(dic)
        #print(dic['trans_result']['data'][0]['dst'])

if __name__ == "__main__":
    traslator = fanyi('苹果')
    traslator.run()