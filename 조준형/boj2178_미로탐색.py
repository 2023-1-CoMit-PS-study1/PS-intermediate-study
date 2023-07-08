from collections import deque


def maze_bfs(n,m,grid):
    shortest_path_len = -1
    row = n
    col = m
    visited = [[False]*col for _ in range(row)]

    
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]
    visited[0][0] = True
    queue = deque()
    queue.append((0,0, 1))
    
    while queue:
        cur_r, cur_c, cur_len = queue.popleft()

        if cur_r == row -1 and cur_c == col-1:
            shortest_path_len = cur_len
            break

        for i in range(4):
            next_r = cur_r + dr[i]
            next_c = cur_c + dc[i]
            if next_r >= 0 and next_r < row and next_c >= 0 and next_c < col:
                if grid[next_r][next_c] == 1 and not visited[next_r][next_c]:
                    queue.append((next_r,next_c, cur_len+1))
                    visited[next_r][next_c] = True
                    
    return shortest_path_len

    
                    


if __name__ == '__main__':

    n, m = map(int, input().split())
    grid = [list(map(int, list(input().strip()))) for _ in range(n)]

    print(maze_bfs(n,m,grid))