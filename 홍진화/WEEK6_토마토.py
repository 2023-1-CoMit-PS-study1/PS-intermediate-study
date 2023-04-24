import sys
from collections import deque
input = sys.stdin.readline


m, n = map(int, input().split())  # 상자의 크기 변수(가로, 세로)
graph = [list(map(int, input().split())) for _ in range(n)]  # 상자 정보 입력
visited = [[False for _ in range(m)] for _ in range(n)]  # 방문 체크 배열 선언
queue = deque()  # 1의 위치가 여러 개인 경우 존재
d = [[-1, 0], [0, 1], [1, 0], [0, -1]]


def bfs():
    count = 0
    while queue:
        changed = False  # 영향을 줬는지 체크
        l = len(queue)  # 현재 영향을 줄 수 있는 토마토 개수에 한해서 loop 진행
        for _ in range(l):
            cur = queue.popleft()
            for k in range(4):
                nx, ny = cur[0] + d[k][0], cur[1] + d[k][1]  # 다음 위치
                if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 0 and not visited[nx][ny]:  # 체크 조건
                    visited[nx][ny] = True
                    graph[nx][ny] = 1
                    queue.append((nx, ny))
                    changed = True
        if changed:  # 영향을 준 경우
            count += 1
    return count  # 변화된 날짜 반환


# 초기 1 위치 탐색
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:  # 현재 1인 위치의 경우
            visited[i][j] = True  # 방문한 것으로 판단
            queue.append((i, j))  # queue에 해당 위치 삽입
# 탐색 값 도출
answer = bfs()
# 잔여 0 탐색
for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            answer = -1
print(answer)
