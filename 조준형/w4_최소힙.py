import heapq
import sys  #파이썬 인터프리터를 제어할 수 있는 방법을 제공한다. 

input = sys.stdin.readline
#한 두줄 입력받는 문제들과는 다르게, 반복문으로 여러줄을 입력받아야 할 때는 이렇게 해준다.

#파이썬 heapq를 사용하면 기본적으로 최소 힙이다. 
min_heap = []

for _ in range(int(input())):
    n = int(input())

    if n==0:
        if len(min_heap):
            print(heapq.heappop(min_heap))
        else:
            print(0)

    else: 
        heapq.heappush(min_heap, n)
