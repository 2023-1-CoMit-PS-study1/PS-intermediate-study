#include <iostream>
using namespace std;

long long int Modulo(int A, int B, int C);      // Modulo 공식을 적용한 값을 반환하는 함수

int main() {
    int A, B, C;
    int res = 1;

    cin >> A >> B >> C;

    cout << Modulo(A, B, C);
}

// A : Dividend | B : Exponent | C : Divisor
long long int Modulo(int A, int B, int C) {
    if(B == 1) return A % C;
    long long int res = 1;

    if(B % 2 != 0) {    // 처음에 B가 홀수이면, A^B를 A^(B-1) * A 로 분리한다.
        B--;
        res *= A % C;
    }

    res *= (Modulo(A, B/2, C) * Modulo(A, B/2, C)) % C;     // A^n mod C = (A^(n/2) mod C * A^(n/2) mod C) % mod C
    return res % C;     // 20번째 줄에 res값이 미리 곱해졌으므로 다시한번 C로 나눈다.
}
