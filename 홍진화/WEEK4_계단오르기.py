import sys
input = sys.stdin.readline
stairs = [0]  # 계단 정보(점수) 입력할 배열, 최대 300개
n = int(input())
for _ in range(n):  # 입력받은 계단의 개수만큼 각 계단 점수 입력
    stairs.append(int(input()))


# 연속된 세 개의 계단을 밟으면 안 됨
# 그러면 일단 세 개보다 적은 경우와 세 개 이상의 경우로 나눔
if n < 3:
    sys.stdout.write(str(sum(stairs)))
else:
    d = [0 for _ in range(n+1)]
    d[1] = stairs[1]
    d[2] = d[1] + stairs[2]
    # 전전, 전, 현재 총 연속 세 개의 계단으로 볼 수 있는데 이 세 개를 모두 밟으면 조건에 어긋남
    # 전전, 현 또는 전, 현의 두 가지 케이스만 존재함
    for i in range(3, n+1):
        d[i] = max(stairs[i] + d[i-2], stairs[i] + stairs[i-1] + d[i-3])
    sys.stdout.write(str(d[n]))
