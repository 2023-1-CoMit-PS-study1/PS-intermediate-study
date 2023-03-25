#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool edge[101][101];

    int num;
    cin>>num;

    int edgeNum;
    int x,y;

    cin>>edgeNum;

    for(int i=0; i<edgeNum; i++){
        cin>>x>>y;
        edge[x][y]=true;
    }

    
    queue<int> queue;

    bool visited[101];
    for(int i=1;i<=num;i++){
        visited[i]=false;
    }


    queue.push(1);
    visited[1]=true;

    int vi=0;

    while(!queue.empty()){
        int now = queue.front();
        queue.pop();

        for(int i=1; i<=num; i++){
            if( (edge[now][i] || edge[i][now] ) && !visited[i] ){
                queue.push(i);
                visited[i]=true;
                vi++;
            }
        }

    }

    cout<<vi<<'\n';
    
}