#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, M, T;
int graph[405][405];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> N >> M;

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(i != j) graph[i][j] = INF;

        for(int i = 0; i < M; i++) {
            int X, Y, C;
            cin >> X >> Y >> C;
            graph[X][Y] = C;
        }

        for(int k = 1; k <= N; k++) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    if(i == k || j == k) continue;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int answer = INF;
        for(int i = 1; i <= N; i++)
            answer = min(answer, graph[i][i]);

        if(answer == INF) answer = -1;
        
        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}