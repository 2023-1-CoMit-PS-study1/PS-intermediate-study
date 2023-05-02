#include <iostream>
using namespace std;

void findTomatoMaze(int** maze, int M, int N, int x, int y);

// 1 : 동쪽 | 2 : 서쪽 | 3 : 남쪽 | 4 : 북쪽
int X_axis[4] = {1, -1, 0, 0};
int Y_axis[4] = {0, 0, 1, -1};

int main() {
    int M, N;
    cin >> M >> N;

    int**tomato = new int*[M];
    for(int i=0; i<M; i++)
        tomato[i] = new int[N];

    int startingPosX, startingPosY;
    int day = 0;            // 토마토가 다 익는 날
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> tomato[i][j];
        }
    }

    // 미로찾기의 시작 위치를 탐색한다
    startingPosX = -1, startingPosY = -1;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(tomato[i][j] == 1) {
                startingPosX = j;
                startingPosY = i;

                break;
            }
        }

        if(startingPosX != -1 && startingPosY != -1) break;
    }

    // 만약 익은 토마토가 존재하지 않으면, 1을 출력한다.
    if(startingPosX == -1 && startingPosY == -1) {
        cout << "-1";
        return 0;
    }

    findTomatoMaze(tomato, startingPosX, startingPosY, M, N);
    int max = 0;

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(tomato[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            if(tomato[i][j] > max) {
                max = tomato[i][j];
            }
        }
    }

    cout << max;
    return 0;
}

void findTomatoMaze(int** maze, int x, int y, int M, int N) {
    for(int i=0; i<4; i++) {
        int nextX = x + X_axis[i];
        int nextY = y + Y_axis[i];

        if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N || maze[nextY][nextX] != 0) continue;
        else if(maze[nextY][nextX] == 0) {
            maze[nextY][nextX] = maze[y][x] + 1;
            findTomatoMaze(maze, nextX, nextY, M, N);
        }
    }
}
