import sys
import heapq
input = sys.stdin.readline


queue = []
for _ in range(int(input())):
    command = int(input())
    if command == 0:
        if queue:
            sys.stdout.write(str(heapq.heappop(queue)) + '\n')
        else:
            sys.stdout.write('0\n')
    else:
        heapq.heappush(queue, command)
