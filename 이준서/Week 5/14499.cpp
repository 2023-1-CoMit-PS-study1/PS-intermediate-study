#include <iostream>
using namespace std;

// 주사위
struct Dice {
    int above = 0;      // 윗 면
    int under = 0;      // 아랫 면
    int side[4] = {0, 0, 0, 0};     // 앞 면, 오른쪽 면, 뒷 면, 왼쪽 면

    // 앞면을 정하는 index
    int side_standard = 0;
};

void pasteToDice(int** Map, int i, int j, int direction, int* answer, int* answerCnt, Dice* dice);  // 주사위를 굴리면, 주사위 바닥면에 Map의 칸 값을 복사하거나 복사시키는 작업을 한다.
void rollDice(int direction, Dice* dice);                                                           // 주사위를 굴린다.

int main() {
    int N, M;
    int x, y;
    int K;
    Dice dice;

    cin >> N >> M >> x >> y >> K;

    // 지도 메모리할당 및 입력
    int** Map = new int*[N];
    for(int i=0; i<N; i++)
        Map[i] = new int[M];
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> Map[i][j];
        }
    }

    // 정답 배열 동적할당
    int* answer = new int[K];
    for(int i=0; i<K; i++) answer[i] = 0;
    int answerCnt = 0;

    int direction;

    // 방향을 입력 받음
    for(int i=0; i<K; i++) {
        int original_x = x, original_y = y;
        
        cin >> direction;
        switch (direction) {
            case 1: y++; break;
            case 2: y--; break;
            case 3: x--; break;
            case 4: x++; break;
        }

        // Map의 범위를 초과하면, 원래 (x, y) 좌표를 돌려받는다
        if(x >= N || y >= M || x < 0 || y < 0) { 
            x = original_x;
            y = original_y;
        }  
        else    // Map의 칸 값을 주사위로 복사하는 작업을 한다.
            pasteToDice(Map, x, y, direction, answer, &answerCnt, &dice);
    }

    // 출력
    for(int i=0; i<answerCnt; i++) cout << answer[i] << '\n';
}

void pasteToDice(int** Map, int i, int j, int direction, int* answer, int* answerCnt, Dice* dice) {

    rollDice(direction, dice);  // 먼저 주사위를 굴려서, 아랫 면과 윗 면을 정한다.

    // Map에서 (i, j) 좌표 값이 0이 아니면, 주사위에 그 값을 복사하고 자신을 0으로 만든다.
    if(Map[i][j] != 0) {
        dice->under = Map[i][j];
        Map[i][j] = 0;
    } else {       // 좌표 값이 0이면, Map 칸에 주사위의 아랫 면 값을 복사한다.
        Map[i][j] = dice->under;
    }

    // 굴려진 주사위의 윗면을 answer 배열에 기록한다.
    answer[(*answerCnt)++] = dice->above;
}

void rollDice(int direction, Dice* dice) {
    int tmp;

    switch(direction) {

        // 동쪽
        case 1:
            tmp = dice->side[(dice->side_standard+1)%4];
            dice->side[(dice->side_standard+1)%4] = dice->above;
            dice->above = dice->side[(dice->side_standard-1) < 0 ? 3 : dice->side_standard-1];
            dice->side[(dice->side_standard-1) < 0 ? 3 : dice->side_standard-1] = dice->under;
            dice->under = tmp;

            break;

        // 서쪽
        case 2:
            tmp = dice->side[(dice->side_standard-1) < 0 ? 3 : dice->side_standard-1];
            dice->side[(dice->side_standard-1) < 0 ? 3 : dice->side_standard-1] = dice->above;
            dice->above = dice->side[(dice->side_standard+1)%4];
            dice->side[(dice->side_standard+1)%4] = dice->under;
            dice->under = tmp;

            break;

        // 북쪽
        case 3:
            tmp = dice->above;
            dice->above = dice->side[dice->side_standard];
            dice->side[dice->side_standard] = dice->under;
            dice->under = dice->side[(dice->side_standard+2)%4];
            dice->side[(dice->side_standard+2)%4] = tmp;

            break;
        
        // 남쪽
        case 4:
            tmp = dice->under;
            dice->under = dice->side[dice->side_standard];
            dice->side[dice->side_standard] = dice->above;
            dice->above = dice->side[(dice->side_standard+2)%4];
            dice->side[(dice->side_standard+2)%4] = tmp;
            
            break;
    }
}
