from collections import deque

def worms(grid):
    number_of_worms = 0
    m = len(grid)    # 세로길이
    n = len(grid[0]) #가로길이
    visited = [[False]*n for _ in range(m)]

    def bfs(x,y):
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        visited[x][y] = True
        queue = deque()
        queue.append((x,y))
        while queue:
            cur_x, cur_y = queue.popleft()
            for i in range(4):
                next_x = cur_x + dx[i]
                next_y = cur_y + dy[i]
                if next_x >= 0 and next_x <= m-1 and next_y >= 0 and next_y <= n-1:
                    if grid[next_x][next_y] == 1 and not visited[next_x][next_y]:
                        visited[next_x][next_y] = True
                        queue.append((next_x,next_y))

    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1 and visited[i][j] == False:
                bfs(i,j)
                number_of_worms += 1

    return number_of_worms

#입력한 값으로 배추밭 그리드를 만들어준다.
iteration = int(input())

for i in range(iteration):
    width, hight,  cabbage_num = map(int, input().split())
    grid = [[0 for _ in range(hight)] for _ in range(width)]
    
    for j in range(cabbage_num):
        x, y = map(int, input().split())
        grid[x][y] = 1
    
    print(worms(grid))
