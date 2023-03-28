n = int(input())
stairs = [int(input()) for _ in range(n)]

if n <= 2:
    print(sum(stairs))
else:
    dp = [0] * n
    dp[0], dp[1] = stairs[0], stairs[0] + stairs[1] # 초기값 설정

    for i in range(2, n):
        dp[i] = max(dp[i-3]+stairs[i-1]+stairs[i], dp[i-2]+stairs[i])

    print(dp[-1])
