import sys
import heapq

input = sys.stdin.readline
heap = []
N = int(input())

for _ in range(N):
    t = int(input())
    if t == 0:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))
        continue
    heapq.heappush(heap, t)
