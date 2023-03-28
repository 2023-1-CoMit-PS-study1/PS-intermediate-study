#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i,int j) {
    return j<i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    vector<int> v;

    int num;
    vector<int> ans;
    for (int i=0;i<N;i++) {
        cin>>num;
        if (num==0) {
            if (v.size()==0) {
                ans.push_back(0);
            }
            else {
                ans.push_back(v.back());
                v.pop_back();
            }
        }
        else {
            int j = v.size() - 1;
            while (j >= 0 && v[j] < num) {
                j--;
            }
            v.insert(v.begin() + j + 1, num);
        }
    }

    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<"\n";
    }
    
    return 0;
}
