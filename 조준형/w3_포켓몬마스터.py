pockemon_num, problem_num = map(int, input().split())

dogam = []
for i in range(pockemon_num):
    dogam.append(input())

for i in range(problem_num):
    quiz = input()

    if quiz.isdigit():
        index = int(quiz)-1
        print(dogam[index])
    else:
        print(dogam.index(quiz)+1)
