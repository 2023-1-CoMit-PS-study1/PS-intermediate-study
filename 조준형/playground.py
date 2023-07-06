from collections import deque

def shortestPathBinaryMatrix(grid):
    shortest_path_len = -1
    row = len(grid)
    col = len(grid[0])

    #첫번째 시작점에  0 이 아닌 1이나 다른 수가 올 경우 -1을 반환해주기 위한 코드
    if grid[0][0] != 0 or grid[row-1][col-1] != 0:
        return shortest_path_len

    visited = [[False] * col for _ in range(row)]

    delta = [(1,0), (-1,0), (0,1), (0,-1), 
             (1,1), (1,-1), (-1,1), (-1,-1)]
    
    queue = deque()
    queue.append((0, 0, 1))

    visited[0][0] = True

    while queue:
        cur_r, cur_c, cur_len = queue.popleft()
        #목적지에 도착했을 때의 curlen을 shortest_path_len으로 반환하면 된다.
        if cur_r == row -1 and cur_c == col - 1:
            shortest_path_len = cur_len
            break

        #연결되어 있는 vertex 확인하가
        for dr,dc in delta:
            next_r = cur_r + dr
            next_c = cur_c + dc
            if next_r >= 0 and next_r < row and next_c >= 0 and next_c < col:
                if grid[next_r][next_c] == 0 and not visited[next_r][next_c]:
                    visited[next_r][next_c] = True
                    queue.append((next_r,next_c, cur_len+1))


    return shortest_path_len


grid = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
print(shortestPathBinaryMatrix(grid))