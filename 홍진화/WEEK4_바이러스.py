import sys
from collections import deque
input = sys.stdin.readline
n = int(input())  # 컴퓨터의 수
k = int(input())  # 연결 수
answer = 0  # 바이러스에 걸리게 되는 컴퓨터의 수


computers = [[] for _ in range(n+1)]
for _ in range(k):  # k개 만큼의 연결 정보 입력
    a, b = map(int, input().split())
    computers[a].append(b)
    computers[b].append(a)
visited = [False for _ in range(n+1)]
visited[1] = True
queue = deque()
queue.append(1)
while queue:
    cur = queue.popleft()
    for i in range(len(computers[cur])):
        if not visited[computers[cur][i]]:
            visited[computers[cur][i]] = True
            queue.append(computers[cur][i])
            answer += 1
            # print(f'cur:{cur}, 추가되는 computer:{computers[cur][i]}, answer:{answer}') -> 결과 테스트
sys.stdout.write(str(answer))
