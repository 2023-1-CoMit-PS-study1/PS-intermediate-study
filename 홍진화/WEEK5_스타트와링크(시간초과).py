import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline
n = int(input())  # N은 짝수이며 최대 20, 최소 4
graph = [list(map(int, input().split())) for _ in range(n)]
members = [i for i in range(1, n+1)]
min_diff = 1_000_000_000


# 팀원 조합을 구하는 함수 생성
def mem_combination(arr, n):
    result = []
    if n == 0:  # 종료 설정
        return [[]]
    for i in range(0, len(arr)):
        item = arr[i]
        for rest in mem_combination(arr[1+i:], n-1):
            result.append([item] + rest)
    return result


# 스타트팀 배열만으로 링크팀까지 계산, 차이 구함
def sum_all(arr):
    s_sum, l_sum = 0, 0
    # 스타트, 링크 팀 합
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i in arr and j in arr and i != j:  # 둘 모두 스타트팀인 경우
                s_sum += graph[i-1][j-1]
            if i not in arr and j not in arr and i != j:  # 둘 모두 링크팀인 경우
                l_sum += graph[i-1][j-1]
    return abs(s_sum - l_sum)  # 두 팀 점수 차이의 절대값 반환


# 모든 조합을 가지고 차이의 최소 구하기
for mem_result in mem_combination(members, n//2):
    min_diff = min(min_diff, sum_all(mem_result))
print(min_diff)
# 시간초과 -> n=20일 때 조합의 개수는 약 184,000개, 2중 for문이 존재하므로 10*10*2만큼 추가로 시간 소요 -> 시간초과
