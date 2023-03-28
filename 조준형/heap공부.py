#지금 내가 해야 되는 것은 힙을 사용하는 코드이다. 
# 내가 힙을 사용할 수 있나? 
#내가 해야 할 것: 힙을 사용하는 법을 이번에 찬찬히 살펴본다.

import sys
import heapq

heap = []
heapq.heappush(heap, 50)
heapq.heappush(heap, 10)
heapq.heappush(heap, 20)

print(heap)
#[10, 50, 20] 이렇게 나오는데 이게 힙으로 정렬이 된 상태라고 한다. 기본적으로 최소 힙인가보다

heap2 = [50 ,10, 20]
heapq.heapify(heap2)

print(heap2)


result = heapq.heappop(heap)

print(result)
print(heap)