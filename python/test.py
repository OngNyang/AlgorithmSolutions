N = int(input())
x,y= 1,1
plans = input().split()

dx = [-1,1,0,0]
dy = [0,0,-1,1]

move_types = ['U','D','L','R']

for i in plans:
    for j in range(len(move_types)):
        if i == move_types[j]:
            nx = x + dx[j]
            ny = y + dy[j]
    if nx <1 or nx > N or ny<1 or ny> N:
        continue
    x, y = nx, ny

print(x, y)