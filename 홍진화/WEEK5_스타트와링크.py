import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
n = int(input())  # N은 짝수이며 최대 20, 최소 4
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [False for _ in range(n)]
result = 1_000_000_000


def dfs(idx, count):
    global result
    if count == n//2:
        s_sum, l_sum = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    s_sum += graph[i][j]
                elif not visited[i] and not visited[j]:
                    l_sum += graph[i][j]
        result = min(result, abs(s_sum-l_sum))
        return
    for k in range(idx, n):
        if not visited[k]:
            visited[k] = True
            dfs(k+1, count+1)
            visited[k] = False


dfs(0, 0)
print(result)
