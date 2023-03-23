#include <iostream>

using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int score[10001];

    cin >> n;
    for(int i=1; i<=n; i++){            //score 입력 받기
        cin >> score[i];
    }                           

    int maxScore[10001];    //to record max score -> to check 011[end] or 101[end]

    int maxSocre_last0[10001];      // to record 101[end] case

    maxScore[0]=0;
    maxSocre_last0[0]=0;

    maxScore[1]=score[1];
    maxSocre_last0[1]=score[1];


    for(int i=2; i<=n; i++){
        maxSocre_last0[i] = (maxScore[i-2] + score[i]);  // 101[end] case
        maxScore[i]=max( maxSocre_last0[i-1] + score[i] , maxScore[i-2] + score[i]);  //max score  011[end] or 101[end] 
    }

    cout<<maxScore[n]<<endl;

}