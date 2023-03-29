import sys
input = sys.stdin.readline
n, m, r, c, k = map(int, input().split())  # 기본 정보 입력
graph = [list(map(int, input().split())) for _ in range(n)]  # 좌표 입력
commands = list(map(int, input().split()))  # 이동 명령이 담긴 배열


def move(dir):
    global r, c
    if dir == 1:  # 동쪽으로 가는 경우
        if c+1 < m:  # graph 범위 밖으로 나가지 않는 경우
            dice[1][0], dice[1][1], dice[1][2], dice[3][1] = dice[3][1], dice[1][0], dice[1][1], dice[1][2]
            change(r, c+1)
            sys.stdout.write(str(dice[1][1]) + '\n')  # 윗면 주사위 숫자 출력
            c += 1
    elif dir == 2:  # 서쪽으로 가는 경우
        if c-1 >= 0:
            dice[1][0], dice[1][1], dice[1][2], dice[3][1] = dice[1][1], dice[1][2], dice[3][1], dice[1][0]
            change(r, c-1)
            sys.stdout.write(str(dice[1][1]) + '\n')  # 윗면 주사위 숫자 출력
            c -= 1
    elif dir == 3:  # 북쪽으로 가는 경우
        if r-1 >= 0:
            dice[0][1], dice[1][1], dice[2][1], dice[3][1] = dice[1][1], dice[2][1], dice[3][1], dice[0][1]
            change(r-1, c)
            sys.stdout.write(str(dice[1][1]) + '\n')  # 윗면 주사위 숫자 출력
            r -= 1
    elif dir == 4:  # 남쪽으로 가는 경우
        if r+1 < n:
            dice[0][1], dice[1][1], dice[2][1], dice[3][1] = dice[3][1], dice[0][1], dice[1][1], dice[2][1]
            change(r+1, c)
            sys.stdout.write(str(dice[1][1]) + '\n')  # 윗면 주사위 숫자 출력
            r += 1


def change(r, c):
    if graph[r][c] == 0:  # 지도 칸의 값이 0인 경우
        graph[r][c] = dice[3][1]
    else:  # 지도 칸의 값이 0이 아닌 경우
        dice[3][1], graph[r][c] = graph[r][c], 0


# 명령의 개수 k가 1000개 이하 -> 그냥 완탐해도 시간초과 x
# 방향 -> {1: 동, 2: 서, 3: 북, 4: 남}
# 주사위의 가장 처음 상태는 모든 면이 0
# 출력은 윗면의 숫자, graph 밖으로 나가려 한다면 출력을 포함한 어떠한 행위도 x
dice = [[0, 0, 0],  # [0, 1] : 북쪽을 바라보는 면
        [0, 0, 0],  # [1, 0], [1, 1], [1, 2] : 서쪽, 윗쪽, 동쪽을 바라보는 면
        [0, 0, 0],  # [2, 1] : 남쪽을 바라보는 면
        [0, 0, 0]]  # [3, 1] : 아랫쪽을 바라보는 면
for command in commands:  # 방향 정보가 담긴 배열을 전부 탐색
    move(command)
