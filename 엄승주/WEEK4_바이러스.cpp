#include <iostream>


using namespace std;

bool edge[101][101];
bool visited[101];
int num;
int vi=-1;


void dfs(int com){
    vi++;
    visited[com]=true;

    for(int i=1; i<=num; i++){
        if( (edge[com][i]==1 || edge[i][com]==1 ) && visited[i]==false ){
            dfs(i);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>num;

    int edgeNum;
    int x,y;
    cin>>edgeNum;
    for(int i=0; i<edgeNum; i++){
        cin>>x>>y;
        edge[x][y]=1;
    }

    for(int i=1;i<=num;i++){
        visited[i]=false;
    }

    dfs(1);

    cout<<vi<<'\n';
    
}