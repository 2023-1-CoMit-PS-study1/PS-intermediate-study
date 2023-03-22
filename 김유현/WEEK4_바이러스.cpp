#include<iostream>
#include<queue>
#include<vector>

int N, M, ans;
int visited[205];
std::vector<int> graph[205];

void bfs(){
    std::queue<int> que;

    que.push(1);
    visited[1] = 1;

    while(!que.empty()){
        int cur = que.front();

        que.pop();
        for(int i = 0; i < graph[cur].size(); ++i){
            int next = graph[cur][i];

            if(!visited[next]){
                visited[next] = 1;
                ++ans;
                que.push(next);
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b;

        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs();
    
    printf("%d\n", ans);

    return 0;
}
