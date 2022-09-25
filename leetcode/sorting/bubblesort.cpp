#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bubbleSort(vector<int> &q){
    for (int i=0;i< q.size();i++){
        for (int j=0;j<q.size()-i;j++){
            if (q[j]>q[j+1]){
                swap(q[j], q[j+1]);
            }
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
    bubbleSort(q);
    for(auto x : q)
        cout << x << ' ';
    cout << endl;
    return 0;
}
