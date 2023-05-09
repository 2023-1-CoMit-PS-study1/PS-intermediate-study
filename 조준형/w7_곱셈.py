def mux(a, b, c):
    temp = []
    n = 0
    for i in range(c):
        cal = a**(i+1) % c
        if (cal in temp):
            break
        else:
            temp.append(cal)
            n += 1
        

    

    answer = temp
    return answer

a, b, c = map(int,input().split())

print(mux(a,b,c))

