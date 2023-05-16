#include <iostream>

int maze[11][11];
int personPos[10][2];
int exit[2];
int escapePerson = 0;
bool escapeCheck[10];

void rotateMaze();
void movePerson();

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for(int i=0; i<M; i++) escapeCheck[i] = false;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++)
            cin >> maze[i][j];
    }

    for(int i=0; i<M; i++) 
        cin >> personPos[i][0] >> personPos[i][1];
    
    cin >> exit[0] >> exit[1];

    int second;
    for(second = 1; second<=K && escapePerson != M; second++) {
        movePerson();
        rotateMaze();
    }

    cout << --second << "\n" << exit[0] << " " << exit[1];

    return 0;
}

void rotateMaze() {
    int xPos = 1, yPos = 1;

    for(int i=1; i<=N; i++) {
        for(int pos=0; pos<M; pos++) {
            if(personPos[pos][0] == i)
            if(personPos[pos][1] == i)
        }
    }
}

void rotateSquare(int start_i, int start_j, int length) {
    int** tmp = new int*[length];
    for(int i=0; i<length; i++)
        tmp[i] = new int[length];

    for(int i=start_i; i<start_i+length; i++) { 
        for(int j=start_j j<start_j+length; j++) {
            tmp[j - start_j][(start_i+length) - i - 1] = maze[i][j];
        }
    }

    for(int i=start_i; i<start_i+length; i++) { 
        for(int j=start_j j<start_j+length; j++) {
            maze[i][j] = tmp[i - start_i][j - start_i];
        }
    }

    for(int i=0; i<length; i++)
        delete[] tmp[i];
    delete[] tmp;
}

void movePerson() {
    int nextX[4] = {1, -1, 0, 0};
    int nextY[4] = {0, 0, 1, -1};

    int dir;

    for(int i=0; i<M; i++) {

        //이미 탈출한 사람인가
        if(escapeCheck[i]) continue;

        // 방향 설정
        if(personPos[i][0] < exit[0]) {             // 사람이 출구보다 상단에 위치할 때
            dir = 2;
        } else if(personPos[i][0] > exit[0]){       // 사람이 출구보다 하단에 위치할 때
            dir = 3;
        } else if(personPos[i][1] < exit[1]) {      // 사람과 출구가 같은 row에 있고, 사람이 출구보다 왼쪽에 위치할 때
            dir = 0;
        } else if(personPos[i][1] > exit[1]) {      // 사람과 출구가 같은 row에 있고, 사람이 출구보다 오른쪽에 위치할 때
            dir = 1;
        }

        // 장애물 판별
        if(maze[personPos[i][1] + nextY[dir]][personPos[i][0] + nextX[dir]] == 0) {     // 만약 장애물이 없다면, 인간이 이동하게 된다.
            personPos[i][0] += nextY[dir];
            personPos[i][1] += nextX[dir];
        }

        // 출구에 도달 시
        if(personPos[i][0] == exit[0] && personPos[i][1] == exit[1]) {
            escapePerson++;
            escapeCheck[i] = true;
        }
    }
}
