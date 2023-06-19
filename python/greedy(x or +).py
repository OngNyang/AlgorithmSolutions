#get input of string array S

#0만 아니면 곱하는게 더 이득인것 아님?

#0이랑 1이면 더하고 아니ㅕㅁ 곱하기

data = input()

result = int(data[0])

for i in range(1, len(data)):
    num = int(data[i])
    if num <=1 or result <=1:
        result += num
    else:
        result *= num
print(result)