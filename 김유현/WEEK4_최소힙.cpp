#include<iostream>
#include<vector>
#include<queue>

std::priority_queue<int, std::vector<int>, std::greater<int>> que;
int N;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int input;

        scanf("%d", &input);
        if(!input){
            if(que.empty())
                puts("0");
            else{
                printf("%d\n", que.top());
                que.pop();
            }
        }
        else{
            que.push(input);
        }
    }
    return 0;
}
