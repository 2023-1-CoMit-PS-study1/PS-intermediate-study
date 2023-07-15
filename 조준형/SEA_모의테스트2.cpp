#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        int N, M, Q;
        cin >> N >> M >> Q;

        vector<vector<int>> grid(N + 1, vector<int>(M + 1, 0));
        vector<int> maxRow(N + 1, 0), maxCol(M + 1, 0);
        vector<int> safeRow(N + 1, 0), safeCol(M + 1, 0);
        int res = 0;
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> grid[i][j];
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (grid[i][j] == maxRow[i] && grid[i][j] == maxCol[j]) {
                    safeRow[i]++;
                    safeCol[j]++;
                    res++;
                }
            }
        }
        
        while(Q--) {
            int r, c, x;
            cin >> r >> c >> x;
            
            if (grid[r][c] == maxRow[r] && safeRow[r] == 1) {
                res--;
            }
            if (grid[r][c] == maxCol[c] && safeCol[c] == 1) {
                res--;
            }
            
            grid[r][c] = x;
            maxRow[r] = max(maxRow[r], x);
            maxCol[c] = max(maxCol[c], x);
            
            safeRow[r] = 0;
            safeCol[c] = 0;
            
            for (int j = 1; j <= M; ++j) {
                if (grid[r][j] == maxRow[r]) {
                    safeRow[r]++;
                }
            }
            
            for (int i = 1; i <= N; ++i) {
                if (grid[i][c] == maxCol[c]) {
                    safeCol[c]++;
                }
            }
            
            if (safeRow[r] == 1) {
                res++;
            }
            if (safeCol[c] == 1) {
                res++;
            }
        }
        cout << '#' << test_case << ' ' << res << '\n';
    }
    return 0;
}
