#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

// 방향 설정 (동 -> 남 -> 서 -> 북 순서)
int Direction_X[4] = {1, 0, -1, 0};
int Direction_Y[4] = {0, 1, 0, -1};

// 유기농 배추 
int searchCabbage(int i, int j, int** arr, bool** visited, int M, int N);

int main() {
    int testCase;
    cin >> testCase;

    for(int t=0; t<testCase; t++) {
        int M, N, K;
        int sum = 0;
        
        cin >> M >> N >> K;

        // 동적할당 및 초기화

        int **CabbageField = new int*[M];   // 배추 농장
        for(int i=0; i<M; i++)
            CabbageField[i] = new int[N];
    
        bool **visited = new bool*[M];      // 방문 표시
        for(int i=0; i<M; i++)
            visited[i] = new bool[N];
        
        for(int i=0; i<M; i++) {            // 초기화
            for(int j=0; j<N; j++) {
                CabbageField[i][j] = 0;
                visited[i][j] = false;
            }
        }

        // 유기농 배추 심기

        int x, y;
        for(int i=0; i<K; i++)
        {
            cin >> x >> y;
            CabbageField[x][y] = 1;
        }

        // 배추 찾기

        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(CabbageField[i][j] == 1 && !visited[i][j])
                    sum += searchCabbage(i, j, CabbageField, visited, M, N);
            }
        }

        cout << sum << '\n';
    }
}

int searchCabbage(int i, int j, int** arr, bool** visited, int M, int N)
{
    if(visited[i][j])   // 이미 방문한 곳이면 함수 종료
        return 0;

    visited[i][j] = true;   // 첫 방문이면 방문 표시

    // 4방향 순회
    for(int dir=0; dir<4; dir++)
    {
        // 다음 방향의 값 저장
        int next_X = Direction_X[dir];      
        int next_Y = Direction_Y[dir];

        // Segmentation Fault 방지
        if((next_X >= 0  && next_Y >= 0 && next_X < M && next_Y < N))
        {
            if(!visited[i + next_X][j + next_Y] && arr[i + next_X][j + next_Y] == 1)
                searchCabbage(i + next_X, j + next_Y, arr, visited, M, N);
        }
    }

    return 1;
}
