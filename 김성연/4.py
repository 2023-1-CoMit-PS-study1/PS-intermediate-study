n, m, r, c, k = map(int, input().split())
dmap = [list(map(int, input().split())) for _ in range(n)]
commands = list(map(int, input().split()))

#    동  서  북  남
dr = [0, 0, -1, 1]
dc = [1, -1, 0, 0]

dice = [0] * 6

for command in commands:
    nr = r + dr[command - 1]
    nc = c + dc[command - 1]

    # 이동하려는 곳이 지도 바깥일 때
    if nr < 0 or nr >= n or nc < 0 or nc >= m:
        continue

    # 주사위 굴리기
    if command == 1:  # 동쪽 이동
        #스와프
        dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
    elif command == 2:  # 서쪽 이동
        dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
    elif command == 3:  # 북쪽 이동
        dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]
    else:  # 남쪽 이동
        dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]

    if dmap[nr][nc] == 0:
        dmap[nr][nc] = dice[5]
    else:
        dice[5] = dmap[nr][nc]
        dmap[nr][nc] = 0

    print(dice[0])

    # 주사위 위치 갱신
    r, c = nr, nc