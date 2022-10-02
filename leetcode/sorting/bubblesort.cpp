#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> &q){
    for (int i=0;i< q.size();i++){
        bool flag =  false;
        for (int j=1;j<q.size()-i;j++){
            if (q[j] < q[j-1]){
                swap(q[j], q[j-1]);
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
}

int main(){
    int n;
    vector<int> q;
    cin >> n;
    for(int i = 0, t; i < n; i++){
        cin >> t;
        q.push_back(t);
    }
    for(auto x : q)
        cout << x << ' ';
    cout << endl;
    bubbleSort(q);
    for(auto x : q)
        cout << x << ' ';
    cout << endl;
    return 0;
}
