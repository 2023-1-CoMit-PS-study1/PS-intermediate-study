#include<iostream>
#include<algorithm>

int N, ans = 100000, board[25][25], comb[25];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    for(int u = 0; u < N; ++u)
        scanf("%d", &board[i][u]);
    
    for(int i = 0; i < N / 2; ++i)
        comb[i] = 1;
    
    do{
        int start = 0, link = 0;

        for(int i = 0; i < N; ++i)
        for(int u = 0; u < N; ++u)
            if(comb[i] == 1 && comb[u] == 1)
                start += board[i][u];
            else if(comb[i] == 0 && comb[u] == 0)
                link  += board[i][u];
        
        ans = std::min(ans, std::abs(start - link));
    }while(std::prev_permutation(comb, comb + N));
    
    printf("%d\n", ans);

    return 0;
}
