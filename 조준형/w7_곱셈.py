def mux(a, b, c):
    temp = [0]*(c+2)    
    for i in range(c):
        temp[i] = a**(i+1) % c
    

    answer = temp
    return answer

a, b, c = map(int,input().split())

print(mux(a,b,c))

