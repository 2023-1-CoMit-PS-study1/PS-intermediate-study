#include<iostream>
#include<cstring>

int N, stairs[305], cache[305][2];

int DP(int cur, int prev){
    if(prev == -1)
        return std::max(DP(cur + 1, 0), DP(cur + 2, 0));
    if(cur > N)
        return -3000000;
    else if(cur == N)
        return stairs[N];

    int &ret = cache[cur][prev];

    if(ret != -1)
        return ret;
    
    if(prev == 0){
        ret = stairs[cur] + std::max(DP(cur + 1, 1), DP(cur + 2, 0));
    }
    else{
        ret = stairs[cur] + DP(cur + 2, 0);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &stairs[i]);
    
    printf("%d\n", DP(0, -1));

    return 0;
}
