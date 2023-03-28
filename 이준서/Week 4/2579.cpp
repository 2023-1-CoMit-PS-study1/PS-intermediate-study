#define MAX(A,B) (A) > (B) ? (A) : (B)

#include <iostream>
using namespace std;

int StairClimbing(int arr[], int size, int currentStair, int continuity);
int MaxCompare(int a, int b);

int main() {
    int num;
    cin >> num;

    int* stair = new int[num];
    for(int i=0; i<num; i++) cin >> stair[i];

    cout << StairClimbing(stair, num, 0, 1);
}

int StairClimbing(int arr[], int size, int currentStair, int continuity) {
    if(currentStair >= size) return -1000000;
    if(continuity >= 3) return -1000000;

    int max = arr[currentStair];
    if(currentStair == size-1) return max;

    max += MAX(StairClimbing(arr, size, currentStair + 1, continuity + 1), StairClimbing(arr, size, currentStair + 2, 1));

    return max;
}
