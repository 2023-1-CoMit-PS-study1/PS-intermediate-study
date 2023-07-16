from collections import deque

def bfs(graph, start_v):
    queue = deque([start_v])
    visited = [start_v]
    while queue:
        cur_v = queue.popleft()
        for next_v in graph[cur_v]:
            if next_v not in visited:
                queue.append(next_v)
                visited.append(next_v)
    return visited

def dfs(graph, cur_v, visited=[]):
    visited.append(cur_v)
    for v in graph[cur_v]:
        if v not in visited:
            visited = dfs(graph, v, visited)
    return visited

#main
n, m, v = map(int, input().split())
start_v = str(v)

graph = dict()
for i in range(n):
    graph[str(i+1)] = []

for i in range(m):
    a,b = map(str, input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()   # sort each time a new edge is added
    graph[b].sort()
# for i in range(n):
#     graph[str(i+1)].sort()
# #print(graph)
# # print(dfs(graph, start_v,[]))
# # print(bfs(graph, start_v))
# #print(n,m, v)

for i in dfs(graph, start_v, []):
    print(i,end=' ')
print()
for i in bfs(graph, start_v):
    print(i, end=' ')
print()