#include <iostream>
#include <list>
using namespace std;

bool counting[101];
int findNoCounting(list<int> *linkedList, list<int> found);

int main() {
    int num, link;
    cin >> num;

    for(int i=1; i<=num; i++) counting[i] = false;
    list<int> *linkedList = new list<int>[num + 1];     // 1~num 까지의 연결리스트를 동적할당

    cin >> link;
    int from, to;
    for(int i=0; i<link; i++) {                         // 이어지는 컴퓨터 from, to를 입력받고, 서로의 연결리스트에 서로를 추가한다.
        cin >> from >> to;
        linkedList[from].push_back(to);
        linkedList[to].push_back(from);
    }

    counting[1] = true;                                 // 1은 이미 세어진 것으로 가정
    cout << findNoCounting(linkedList, linkedList[1]);  // 1과 연결된 모든 컴퓨터의 수를 탐색
}

int findNoCounting(list<int> *linkedList, list<int> found) {
    int cnt = 0;                                        // 연결된 컴퓨터의 수
    list<int>::iterator itr = found.begin();

    while(itr != found.end()) {         // 리스트의 모든 숫자가 탐색될 때까지 반복
        if(!counting[*itr])             // 리스트 원소가 탐색되지 않은 숫자라면
        {
            counting[*itr] = true;      // 탐색된 것으로 표시
            cnt++;
            cnt += findNoCounting(linkedList, linkedList[*itr]);    // 리스트 원소와 연결되어있는 리스트를 탐색
        }

        itr++;
    }

    return cnt;     // 연결된 컴퓨터의 수를 반환함
}
