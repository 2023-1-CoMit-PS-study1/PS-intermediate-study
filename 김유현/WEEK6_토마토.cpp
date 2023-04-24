#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int N, M, box[1005][1005];
std::queue<pp> que;

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < M;
}
int BFS(){
    int max = -2;

    while(!que.empty()){
        int r = que.front().first, c = que.front().second;

        que.pop();
        for(int i = 0; i < 4; ++i){
            int R = r + y[i], C = c + x[i];

            if(possible(R, C) && !box[R][C]){
                box[R][C] = box[r][c] + 1;
                que.push({R, C});
            }
        }
    }
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < M; ++u){
        if(box[i][u] == 0)
            return -1;
        max = std::max(max, box[i][u]);
    }
    return max - 1;
}

int main() {

    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; ++i){
        for(int u = 0; u < M; ++u){
            scanf("%d", &box[i][u]);
            if(box[i][u] == 1)
                que.push({i, u});
        }
    }
    printf("%d\n", BFS());
    return 0;
}
