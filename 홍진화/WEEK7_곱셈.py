a, b, c = map(int, input().split())


def recur(num, i, mo):
    if i == 1:  # 지수가 1 -> 그대로 반환
        return num % mo
    elif i % 2 == 0:  # 지수가 짝수 -> 2로 나눈 후 반환
        res = recur(num, i//2, mo)
        return res * res % mo
    else:  # 지수가 홀수
        res = recur(num, i//2, mo)
        return res * res * num % mo


print(recur(a, b, c))
