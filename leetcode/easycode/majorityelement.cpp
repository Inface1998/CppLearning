#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
class Solution{
public:
    int majEle(vector<int>& nums){
        int x = nums.size()/2;
        map<int,int> mp;
        for (int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        int a = 0;
        for(auto it:mp)
        {
            if(it.second > x)
            {a=it.first;}
        }
        return a;
    }

    int maxProfit(vector<int>& prices) {
        int minIndex = 0;
        int maxIndex = 0;
        int profit = 0;
        for(int i = 1;i < prices.size(); i++){
            if (prices[i] > prices[maxIndex]){
                maxIndex = i;
            }else if(prices[i] < prices[minIndex]){
                minIndex = i;
            }
            profit = max(prices[maxIndex] - prices[minIndex], profit);
        }
        return profit;
    }
};

int main(){
    // int n;
    // vector<int> q;
    // cin >> n;
    // for(int i = 0, t; i < n; i++){
    //     cin >> t;
    //     q.push_back(t);
    // }
    // for(auto x : q)
    //     cout << x << ' ';
    // cout << endl;
    // int res = Solution().majEle(q);
    // cout << res << endl;
    // return 0;
    int res = 0;
    vector<int> arr = {1,11,2,5,6};

    res = Solution().maxProfit(arr);
    cout << res << endl;
}
