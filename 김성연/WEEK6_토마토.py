from collections import deque
import sys

dxs = [-1, 0, 1, 0]
dys = [0, -1, 0, 1]

m,n = map(int, sys.stdin.readline().rstrip().split())

board = []
q = deque()
visited = set() #중복 허용X

for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            q.append((i, j))
            visited.add((i, j))

def bfs():
    step = 0
    while q: #현재 step에서 모든 좌표 
        for i in range(len(q)): 
            x,y = q.popleft()
            for dx, dy in zip(dxs, dys):
                nx, ny = x + dx, y + dy

                if nx>=0 and nx<n and ny>=0 and ny<m and (nx,ny) not in visited and board[nx][ny] != -1:
                    q.append((nx, ny))
                    visited.add((nx, ny))
                    board[nx][ny] = 1
        step+= 1

    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                return -1
    return step-1

print(bfs())
