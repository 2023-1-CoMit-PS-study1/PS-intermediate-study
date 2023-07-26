from collections import deque

def tomato_bfs(row,col,grid):


    visited = [[False]*col for _ in range(row)]

    pass


#main
m, n = map(int, input().split())
grid = [ list(map(int, list(input().split()))) for _ in range(n)]

print(tomato_bfs(n,m,grid))
#print(grid)