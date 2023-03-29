#include<iostream>
#include<algorithm>
#include<queue>
#define pp std::pair<int, int>

//                >  <   ^  V
const int y[4] = {0, 0, -1, 1};
const int x[4] = {1, -1, 0, 0};
//            앞 위  뒤 밑 왼  오
//             0  1  2  3  4  5
int dice[6] = {0, 0, 0, 0, 0, 0};
int N, M, K, map[25][25];
int cur_r, cur_c;

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
void roll(int dir){
    int tmp;
    // >  1 5 3 4
    if(dir == 0){
        tmp = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
    }
    // <  4 3 5 1
    else if(dir == 1){
        tmp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = tmp;
    }
    // ^ 3 2 1 0
    else if(dir == 2){
        tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = tmp;
    }
    
    // V  0 1 2 3
    else if(dir == 3){
        tmp = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[0];
        dice[0] = tmp;
    }
}
void step(int dir){
    if(possible(cur_r + y[dir], cur_c + x[dir])){
        cur_r += y[dir];
        cur_c += x[dir];
        roll(dir);
        if(map[cur_r][cur_c] == 0)
            map[cur_r][cur_c] = dice[3];
        else{
            dice[3] = map[cur_r][cur_c];
            map[cur_r][cur_c] = 0;
        }
        printf("%d\n", dice[1]);
    }
}

int main() {
    scanf("%d %d %d %d %d", &N, &M, &cur_r, &cur_c, &K);

    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u)
        scanf("%d", &map[i][u]);
    
    for(int i = 0; i < K; ++i){
        int dir;

        scanf("%d", &dir);
        step(dir - 1);
    }

    return 0;
}
