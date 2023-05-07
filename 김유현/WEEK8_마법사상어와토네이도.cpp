#include<iostream>
#include<algorithm>
#define pp std::pair<int, int>

//                V  >  ^   <
const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};

int N, desert[505][505];
int sr, sc, step_size = 1, d = 3, sand_away = 0;

bool possible(int r, int c){
    return r >= 0 && r < N && c >= 0 && c < N;
}
int dc(int dir){
    return (dir + 4) % 4;
}
void step(){
    int cur_sand = desert[sr + y[d]][sc + x[d]];
    int used_sand = 0;

    //   5
    //  731 
    // 9ayx
    //  842
    //   6
    // 1
    if(possible(sr + y[dc(d + 1)], sc + x[dc(d + 1)])){
        desert[sr + y[dc(d + 1)]][sc + x[dc(d + 1)]] += (int)(cur_sand * 0.01);
        used_sand += (int)(cur_sand * 0.01);
    }
    else{
        sand_away += (int)(cur_sand * 0.01);
        used_sand += (int)(cur_sand * 0.01);
    }
    // 2
    if(possible(sr + y[dc(d - 1)], sc + x[dc(d - 1)])){
        desert[sr + y[dc(d - 1)]][sc + x[dc(d - 1)]] += (int)(cur_sand * 0.01);
        used_sand += (int)(cur_sand * 0.01);
    }
    else{
        sand_away += (int)(cur_sand * 0.01);
        used_sand += (int)(cur_sand * 0.01);
    }
    // 3
    if(possible(sr + y[dc(d)] + y[dc(d + 1)], sc + x[dc(d)] + x[dc(d + 1)])){
        desert[sr + y[dc(d)] + y[dc(d + 1)]][sc + x[dc(d)] + x[dc(d + 1)]]  += (int)(cur_sand * 0.07);
        used_sand += (int)(cur_sand * 0.07);
    }
    else{
        sand_away += (int)(cur_sand * 0.07);
        used_sand += (int)(cur_sand * 0.07);
    }
    // 4
    if(possible(sr + y[dc(d)] + y[dc(d - 1)], sc + x[dc(d)] + x[dc(d - 1)])){
        desert[sr + y[dc(d)] + y[dc(d - 1)]][sc + x[dc(d)] + x[dc(d - 1)]]  += (int)(cur_sand * 0.07);
        used_sand += (int)(cur_sand * 0.07);
    }
    else{
        sand_away += (int)(cur_sand * 0.07);
        used_sand += (int)(cur_sand * 0.07);
    }
    // 5
    if(possible(sr + y[dc(d)] + y[dc(d + 1)] + y[dc(d + 1)], sc + x[dc(d)] + x[dc(d + 1)] + x[dc(d + 1)])){
        desert[sr + y[dc(d)] + y[dc(d + 1)] + y[dc(d + 1)]][sc + x[dc(d)] + x[dc(d + 1)] + x[dc(d + 1)]]  += (int)(cur_sand * 0.02);
        used_sand += (int)(cur_sand * 0.02);
    }
    else{
        sand_away += (int)(cur_sand * 0.02);
        used_sand += (int)(cur_sand * 0.02);
    }
    // 6
    if(possible(sr + y[dc(d)] + y[dc(d - 1)] + y[dc(d - 1)], sc + x[dc(d)] + x[dc(d - 1)] + x[dc(d - 1)])){
        desert[sr + y[dc(d)] + y[dc(d - 1)] + y[dc(d - 1)]][sc + x[dc(d)] + x[dc(d - 1)] + x[dc(d - 1)]]  += (int)(cur_sand * 0.02);
        used_sand += (int)(cur_sand * 0.02);
    }
    else{
        sand_away += (int)(cur_sand * 0.02);
        used_sand += (int)(cur_sand * 0.02);
    }
    // 7
    if(possible(sr + y[dc(d)] + y[dc(d)] + y[dc(d + 1)], sc + x[dc(d)] + x[dc(d)] + x[dc(d + 1)])){
        desert[sr + y[dc(d)] + y[dc(d)] + y[dc(d + 1)]][sc + x[dc(d)] + x[dc(d)] + x[dc(d + 1)]]  += (int)(cur_sand * 0.1);
        used_sand += (int)(cur_sand * 0.1);
    }
    else{
        sand_away += (int)(cur_sand * 0.1);
        used_sand += (int)(cur_sand * 0.1);
    }
    // 8
    if(possible(sr + y[dc(d)] + y[dc(d)] + y[dc(d - 1)], sc + x[dc(d)] + x[dc(d)] + x[dc(d - 1)])){
        desert[sr + y[dc(d)] + y[dc(d)] + y[dc(d - 1)]][sc + x[dc(d)] + x[dc(d)] + x[dc(d - 1)]]  += (int)(cur_sand * 0.1);
        used_sand += (int)(cur_sand * 0.1);
    }
    else{
        sand_away += (int)(cur_sand * 0.1);
        used_sand += (int)(cur_sand * 0.1);
    }
    // 9
    if(possible(sr + y[dc(d)] * 3, sc + x[dc(d)] * 3)){
        desert[sr + y[dc(d)] * 3][sc + x[dc(d)] * 3] += (int)(cur_sand * 0.05);
        used_sand += (int)(cur_sand * 0.05);
    }
    else{
        sand_away += (int)(cur_sand * 0.05);
        used_sand += (int)(cur_sand * 0.05);
    }
    // a
    if(possible(sr + y[dc(d)] * 2, sc + x[dc(d)] * 2)){
        desert[sr + y[dc(d)] * 2][sc + x[dc(d)] * 2] += cur_sand - used_sand;
    }
    else{
        sand_away += cur_sand - used_sand;
    }

    sr += y[d];
    sc += x[d];
}
void tornado(){
    while(1){
        for(int i = 0; i < step_size; ++i){
            step();
            if(sr == 0 && sc == 0)
                break;
        }
        if(sr == 0 && sc == 0)
            return;
        d = (d + 1) % 4;
        for(int i = 0; i < step_size; ++i){
            step();
        }
        d = (d + 1) % 4;
        ++step_size;

    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &desert[i][u]);
    
    sr = sc = N / 2;

    tornado();

    printf("%d\n", sand_away);

    return 0;
}
