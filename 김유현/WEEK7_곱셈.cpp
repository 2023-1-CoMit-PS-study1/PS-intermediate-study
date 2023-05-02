#include<iostream>
#define ll long long

ll A, B, C;

ll power(ll A, ll B, ll C){
    if(!B) return 1;

    ll ret = power(A, B / 2, C) % C;

    ret = ret * ret;
    ret %= C;
    if(B & 1){    
        ret *= A;
        ret %= C;
    }
    return ret;
}

int main() {
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld\n", power(A, B, C));
    
    return 0;
}
