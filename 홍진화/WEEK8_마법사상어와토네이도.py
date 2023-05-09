n = int(input())  # 격자의 크기
graph = [list(map(int, input().split())) for _ in range(n)]  # 격자 정보
sand = [  # 모래 이동 비율 / 순서대로 left, down, right, up
    [[0, 0, 0.02, 0, 0], [0, 0.1, 0.07, 0.01, 0], [0.05, 0, 0, 0, 0], [0, 0.1, 0.07, 0.01, 0], [0, 0, 0.02, 0, 0]],
    [[0, 0, 0, 0, 0], [0, 0.01, 0, 0.01, 0], [0.02, 0.07, 0, 0.07, 0.02], [0, 0.1, 0, 0.1, 0], [0, 0, 0.05, 0, 0]],
    [[0, 0, 0.02, 0, 0], [0, 0.01, 0.07, 0.1, 0], [0, 0, 0, 0, 0.05], [0, 0.01, 0.07, 0.1, 0], [0, 0, 0.02, 0, 0]],
    [[0, 0, 0.05, 0, 0], [0, 0.1, 0, 0.1, 0], [0.02, 0.07, 0, 0.07, 0.02], [0, 0.01, 0, 0.01, 0], [0, 0, 0, 0, 0]],
]
answer = 0  # 격자 밖으로 나간 모래 양 계산


pos = [n//2, n//2]  # 토네이도의 초기 위치
d = [[0, -1], [1, 0], [0, 1], [-1, 0]]
cur_direction = 0  # 현재 방향 index - 순서대로 0: left, 1: down, 2: right, 3: up
cur_change = 0  # 방향 전환 횟수
max_movement = 1  # 한 방향 최대 이동 횟수
while pos[0] != 0 or pos[1] != 0:
    count = 0  # 현재 방향에서 이동 횟수 count
    while count != max_movement:
        pos[0], pos[1] = pos[0] + d[cur_direction][0], pos[1] + d[cur_direction][1]  # 위치 y로 이동
        cur_sand, graph[pos[0]][pos[1]] = graph[pos[0]][pos[1]], 0  # y 위치의 모래양, 해당 위치 모래는 0으로 변함
        moved_sand = 0  # 유의미하게 이동한 모래양
        for i in range(5):  # y는 sand 배열의 정중앙
            for j in range(5):
                tmp_sand = int(cur_sand * sand[cur_direction][i][j])
                if tmp_sand != 0:  # 계산 가능한 모래인 경우만
                    if 0 <= pos[0]+(i-2) < n and 0 <= pos[1]+(j-2) < n:  # 격자 안
                        graph[pos[0]+(i-2)][pos[1]+(j-2)] += tmp_sand
                    else:  # 격자 밖
                        answer += tmp_sand
                    moved_sand += tmp_sand  # 이동한 모래 양 체크
        if 0 <= pos[0] + d[cur_direction][0] < n and 0 <= pos[1] + d[cur_direction][1] < n:
            graph[pos[0] + d[cur_direction][0]][pos[1] + d[cur_direction][1]] += (cur_sand - moved_sand)  # 남은 모래 a 위치
        else:
            answer += (cur_sand - moved_sand)
        count += 1

        '''
        for i in range(n):
            for j in range(n):
                print(graph[i][j], end=' ')
            print()
        print(f'pos:{pos}, count:{count}, max_movement:{max_movement}')
        print()
        '''

        if pos[0] == 0 and pos[1] == 0:
            break

    cur_direction = cur_direction + 1 if cur_direction != 3 else 0
    cur_change += 1
    if cur_change % 2 == 0:
        max_movement += 1

print(answer)
