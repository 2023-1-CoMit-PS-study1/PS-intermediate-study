n, m = map(int, input().split())

# 포켓몬 번호와 이름을 저장할 딕셔너리 생성
name_to_num = {}
num_to_name = {}

for i in range(1, n+1):
    name = input().strip()
    name_to_num[name] = i
    num_to_name[i] = name

# 문제를 하나씩 처리하며 출력
for _ in range(m):
    q = input().strip()
    if q.isdigit():
        # 숫자가 입력된 경우, 해당 번호의 포켓몬 이름 출력
        num = int(q)
        print(num_to_name[num])
    else:
        # 문자열이 입력된 경우, 해당 이름의 포켓몬 번호 출력
        name = q
        print(name_to_num[name])
