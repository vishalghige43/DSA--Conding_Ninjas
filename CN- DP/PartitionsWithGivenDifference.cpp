#include<iostream>
#include<vector>
using namespace std;

int solve_rec(int i,int sum,vector<int> &arr){
    if(i==arr.size()-1 )return sum==arr[i];
    if(sum==0)return 1;
    
    int take=0;
    if(sum>=arr[i])
    take=solve_rec(i+1,sum-arr[i],arr);
    int notTake=solve_rec(i+1,sum,arr);

    return take+notTake;
}


int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];

    if((sum-d)%2==1 || sum<d)return 0;

    return solve_rec(0,(sum-d)/2,arr);
}    

int main(){

    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    cout<<countPartitions(4,0,input);
    
    return 0;
}