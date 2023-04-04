import sys

input = sys.stdin.readline
#sys.stdin.readline()을 사용하는 이유는 반복문으로 여러줄을 받을 때, 시간초과를 하지 않기 위합이다.


n,m,x,y,k = map(int, input().split())
#여러개의 인풋을 한줄에 받아주기!

#이제 k개 만큼의 명령을 반복해 주면 된다
graph = []
for i in range(n):
    row = list(map(int, input().split()))
    if len(row) != m:
        print(f"올바른 개수의 요소를 입력해주세요. (요구 개수: {m})")
    graph.append(row)


print(graph)


