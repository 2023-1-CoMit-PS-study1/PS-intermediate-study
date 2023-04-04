import sys

input = sys.stdin.readline
#sys.stdin.readline()을 사용하는 이유는 반복문으로 여러줄을 받을 때, 시간초과를 하지 않기 위합이다.


dr = [0, 0, 0, -1, 1]
dc = [0, 1, -1, 0, 0]

n,m,x,y,k = map(int, input().split())
#여러개의 인풋을 한줄에 받아주기!

#세로 크기n, 가로크기 m의 지도를 이중배열로 만들어줌
# Map = []
# for i in range(n):
#     row = list(map(int, input().split()))
#     if len(row) != m:
#         print(f"올바른 개수의 요소를 입력해주세요. (요구 개수: {m})")
#     Map.append(row)
maps = [list(map(int, input().split())) for _ in range(n)]

#print(graph)
#이제 k개 만큼의 줌명령을 반복해 주면 된다
inst = list(map(int, input().split()))
dice = [0]*5

#시간 다되서 보고 함
#nx, ny로 하는게 알던 방법이긴 했는데 적용하지 못했다.
# 


for d in inst:
    nx = x + dr[d]
    ny = y + dc[d]

    if not 0 <= nx < n or not 0 <= ny < m:      ## 범위 밖에 있는 좌표면 continue
        continue

    ## 헷갈리기 때문에 방향으로 명시해줌
    east, west, south, north, up, down = dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]

    ### 방향에 따라 주사위 굴리기
    if d == 1:
        dice[0], dice[1], dice[4], dice[5] = down, up, east, west
    elif d == 2:
        dice[0], dice[1], dice[4], dice[5] = up, down, west, east
    elif d == 3:
        dice[2], dice[3], dice[4], dice[5] = up, down, north, south
    elif d == 4:
        dice[2], dice[3], dice[4], dice[5] = down, up, south, north

    ## 지도에 숫자가 0일 때
    if maps[nx][ny] == 0:
        maps[nx][ny] = dice[5]
    ## 지도의 숫자가 0이 아닐 때
    else:
        dice[5] = maps[nx][ny]
        maps[nx][ny] = 0

    ## 꼭 값을 갱신해주기!
    x, y = nx, ny
    print(dice[4])
