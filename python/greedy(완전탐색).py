# get input of integer N 
# 60 단위시간계 system 만들기
# 3포함
# 하나의 정수처럼 받고 for if문으로 그중 3있는지 검사

h = int(input())

count = 0

for i in range(h +1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                count += 1

print(count)
