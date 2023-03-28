#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> arr;     // 우선순위 큐 생성(최소 힙)
    int res[100000];            // result 값을 저장할 배열 생성

    int num, zeroCount = 0, index = 0;
    for(int i=0; i<N; i++) {
        cin >> num;
        
        if(num == 0)        // 0을 입력받으면
        {
            zeroCount++;

            if(arr.empty())                     // 입력된 배열이 하나도 없으면
            {     
                res[index++] = 0;               // 배열에 0 추가
            }
            else
            {
                res[index++] = arr.top();       // 배열에 큐에서 저장된 최솟값 추가
                arr.pop();                      // 큐 삭제
            }
        }
        else                // 0이 아니면
            arr.push(num);                      // 큐 추가
    }

    for(int i=0; i<zeroCount; i++) cout << res[i] << '\n';          // 모든 배열 출력
}
