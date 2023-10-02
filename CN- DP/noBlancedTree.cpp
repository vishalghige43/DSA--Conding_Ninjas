#include<iostream>
#include<cmath>
using namespace std;
int noBalancedTreeHelper(int n,int *ans){
    if(ans[n]!=-1)return ans[n];
    if(n<=1){
        ans[n]=1;
        return 1;
    }
    int x=noBalancedTreeHelper(n-1,ans);
    int y=noBalancedTreeHelper(n-2,ans);
    int mod=pow(10,9)+7;
    int a=((long)x*x)%mod;
    int b=((long)x*y*2)%mod;
    int output=a+b;
    ans[n]=output;
    return output;
}
int noBalancedTree(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    noBalancedTreeHelper(n,ans);
    return ans[n];
}
int noBalancedTreeDp(int n){
    int *ans=new int[n+1];
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        int x=ans[i-1];
        int y=ans[i-2];
        int mod=pow(10,9)+7;
        int a=((long)x*x)%mod;
        int b=((long)x*y*2)%mod;
        ans[i]=a+b;
    }
    return ans[n];
}
int main(){
    cout<<noBalancedTreeDp(1)<<endl;
    cout<<noBalancedTreeDp(2)<<endl;
    cout<<noBalancedTreeDp(3)<<endl;
    cout<<noBalancedTreeDp(4)<<endl;
    cout<<noBalancedTreeDp(5)<<endl;
    cout<<noBalancedTreeDp(6)<<endl;
    

    return 0;
}