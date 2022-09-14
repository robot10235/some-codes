
s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"

left = []
star = []

for i in range(len(s)):
    if s[i] == '(':
        left.append(i)
    elif s[i] == '*':
        star.append(i)
    else:
        if len(left) > 0:
            left.pop()
        elif len(star) > 0:
            star.pop()
        else:
            print(False)

if len(star) < len(left):
    print(False)

flag = 1

while len(left) > 0:
    if left[-1] > star[-1]:
        print(False)
        flag = 0
        break
    else:
        left.pop()
        star.pop()
if flag:
    print(True)