import sys  #파이썬 인터프리터를 제어할 수 있는 방법을 제공한다. 

input = sys.stdin.readline


n = int(input())
m = int(input())
graph = [[]*n for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    
count_virus = 0
visited =[]

def dfs(cur_v):
    visited.append(cur_v)
    global count_virus
    for v in graph[cur_v]:
        if v not in visited:
            dfs(v)
            count_virus +=1
 
dfs(1)
print(visited)
print(graph)
print(count_virus)