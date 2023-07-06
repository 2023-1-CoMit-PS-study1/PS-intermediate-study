from collections import deque


def maze_bfs(n,m,grid):
    count = 0
    row = n
    col = m
    visited = [[False]*col for _ in range(row)]

    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    visited[0][0] = True
    queue = deque()
    queue.append((0,0))
    count += 1
    while queue:
        cur_x, cur_y = queue.popleft()

        
        for i in range(4):
            next_x = cur_x + dx[i]
            next_y = cur_y + dy[i]
            if next_x >= 0 and next_x < col and next_y >= 0 and next_y < row:
                if grid[next_x][next_y] == 1 and not visited[next_x][next_y]:
                    queue.append((next_x,next_y))
                    visited[next_x][next_y] = True

    












if __name__ == '__main__':

    n, m = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
