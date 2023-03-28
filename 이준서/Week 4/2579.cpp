#define MAX(A,B) (A) > (B) ? (A) : (B)

#include <iostream>
using namespace std;

int StairClimbing(int arr[], int size, int currentStair, int continuity);

int main() {
    int num;
    cin >> num;

    int* stair = new int[num];
    for(int i=0; i<num; i++) cin >> stair[i];

    cout << StairClimbing(stair, num, 0, 1);
}

int StairClimbing(int arr[], int size, int currentStair, int continuity) {
    if(currentStair >= size) return -1000000;       // 현재 계단이 마지막 계단을 넘어서면 최솟값 반환
    if(continuity >= 3) return -1000000;            // 계단을 3번 이상 연속으로 오르면 최솟값 반환

    int max = arr[currentStair];
    if(currentStair == size-1) return max;          // 마지막 계단에 정확히 오르는 것에 성공하면, 현재 계단의 점수를 반환

    // 1번씩 오르는 것과 2번씩 오르는 것 중, 최댓값만을 반환하여 max에 더함
    max += MAX(StairClimbing(arr, size, currentStair + 1, continuity + 1), StairClimbing(arr, size, currentStair + 2, 1));

    return max;
}
 
