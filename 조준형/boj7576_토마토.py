from collections import deque

def tomato_bfs(row,col,grid):

    day = 0
    #visited = [[False]*col for _ in range(row)]

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    queue = deque()
    
    for i in range(row):
        for j in range(col):
            if grid[i][j] == 1:
                queue.append((i,j,0))

    while queue:
        cur_x, cur_y, cur_day = queue.popleft()

        if day < cur_day:
            day = cur_day
        
        for i in range(4):
            next_x = cur_x + dx[i]
            next_y = cur_y + dy[i]
            if next_x >= 0 and next_x < row and next_y >= 0 and next_y < col:
                if grid[next_x][next_y] == 0:
                    queue.append((next_x,next_y,cur_day+1))
                    grid[next_x][next_y] = 1

    for i in range(row):
        for j in range(col):
            if grid[i][j] == 0:
                return -1

    return day


#main
m, n = map(int, input().split())
grid = [ list(map(int, list(input().split()))) for _ in range(n)]

print(tomato_bfs(n,m,grid))
#print(grid)