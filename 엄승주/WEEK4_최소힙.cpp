#include <iostream>

using namespace std;

int heap[100001];
int heapcheck = 1;


void push(int x){
    heap[heapcheck]=x;      //맨 끝에 넣기
    int index = heapcheck;  //index지정

    while(index!=1){        //맨 위 인덱스 될때 까지 진행
        if(heap[index] < heap[index/2] ){   //부모가 더 크면
            int temp= heap[index];
            heap[index]=heap[index/2];
            heap[index/2]=temp;
            index = index/2;                // 부모 인덱스로 변경
            continue;
        }
        break;  //부모가 더 작으면 끝
    }

    heapcheck++;    // 힙 크기 늘리기
}

int pop(){
    if(heapcheck==1){   //비어 있으면 
        return 0;
    }

    int ret = heap[1];
    heap[1]=heap[heapcheck-1];
    int index=1;

    while(1){

        if(index*2 > heapcheck-1){  //자식 없는 경우
            break;
        }
        else if(index*2 == heapcheck -1){   //자식 한쪽만 남은 경우
            if(heap[index]>heap[index*2]){  //자식보다 크면 바꿈
                int temp = heap[index];
                heap[index]=heap[index*2];
                heap[index*2]=temp;
            }
            break;
        }
        
        //양 자식 전부 존재시
        if(heap[index]<=heap[index*2] && heap[index]<=heap[index*2+1]){ //모든 자식보다 작음
            break;
        }

        // 적어도 한쪽의 자식보다는 큼 -> 바꿔야함
        if( heap[index*2] <= heap[(index*2)+1]){ //왼쪽이 더 작음
            int temp = heap[index];
            heap[index]=heap[index*2];
            heap[index*2]=temp;
            index=index*2;
        }
        else{   //오른쪽이 더 작음
            int temp = heap[index];
            heap[index]=heap[index*2+1];
            heap[index*2+1]=temp;
            index=index*2+1;
        }
            
    }/*while(1)*/

    heapcheck--;

    return ret;
}

int main(){

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
    cin>> num;

    int input;
    for(int i=0; i<num; i++){
        cin>>input;
        if(input>0){
            push(input);
        }
        else if(input==0){
            cout<<pop()<<"\n";
        }
    }
}