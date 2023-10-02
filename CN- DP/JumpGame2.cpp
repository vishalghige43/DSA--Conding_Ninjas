#include<iostream>
#include<vector>
using namespace std;

int jumpHelper(vector<int>& nums,int i) {
    if(i>=nums.size()-1){
        return 0;
    }
    int ans1=jumpHelper(nums,i+1);
    int ans2=jumpHelper(nums,i+nums[i]);
    return min(ans1,ans2)+1;
}
int jumpDp(vector<int>& nums){
    vector<int>dp(nums.size(),0);
    dp[nums.size()-1]=0;
    for(int i=nums.size()-2;i>=0;i--){
        dp[i]=0;
        if(dp[i]+nums[i]<=nums.size()-1){
            dp[i]=dp[i+nums[i]]+1;
        }
        dp[i]=min(dp[i+1]+1,dp[i]);
    }
    return dp[0];
}
    
int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    // v.push_back(2);
    // v.push_back(1);
    cout<<jumpDp(v)<<endl;
    
    return 0;
}