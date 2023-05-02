import sys
def power(a, b):
    if b == 0:
        return 1
    elif b%2 == 0:
        t = power(a, b//2)
        return t**2 % z
    else:
        return power(a, b-1) * a % z

x,y,z = map(int,sys.stdin.readline().rstrip().split())

print(power(x,y))
