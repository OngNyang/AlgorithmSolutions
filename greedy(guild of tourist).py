#guild of tourist

#get input of N

#get input of point of fear

#제일 작은 값들끼리 짝을 이루도록 

#오름차순으로 정렬

#공포도1이면 혼자서 1파티

#공포도 2이면 2끼리 2명

n = int(input())
data = list(map(int, input().split()))
data.sort() #오름차순

result = 0
count = 0

for i in data:
    count += 1
    if count >= i:
        result += 1
        count =0
print(result)