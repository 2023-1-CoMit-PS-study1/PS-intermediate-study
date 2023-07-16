from collections import deque

def bfs(graph, start_v):
    queue = deque(start_v)
    visited = [start_v]
    while queue:
        cur_v = queue.popleft()
        for next_v in graph[cur_v]:
            if next_v not in visited:
                queue.append(next_v)
                visited.append(next_v)
    #print(visited)
    return len(visited)-1


#main 
com_number = int(input())
linked_com_number = int(input())

#graph = [[] for _ in range(com_number+1)]
graph = dict()
for i in range(com_number):
    graph[str(i+1)] = []

for i in range(linked_com_number):
    a, b = map(int, input().split())
    graph[str(a)].append(str(b))
    graph[str(b)].append(str(a))

#print(graph)
print(bfs(graph, '1'))