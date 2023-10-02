#include<iostream>
#include<cmath>
using namespace std;
// TODO--- DP version of this problem
// int minimumCountDp(int n){
//     int *ans=new int(n+1);
//     ans[0]=1;
//     for(int i=1;i*i<=n;i++){
//         ans[i*i]=1;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;i<)
//     }
// }
int minimumCountHelper(int n,int *list){
    if(list[n]!=-1){
        return list[n];
    }
    int a=sqrt(n);
    if(a*a==n){
        list[n]=1;
        return 1;
    }
    int minimum=INT_MAX;
    for(int i=1;i*i<=n;i++){
        int ans=minimumCountHelper(n-(i*i),list)+1;
        minimum=min(minimum,ans);
    }
    list[n]=minimum;
    return minimum;
}
int minimumCount(int n){
    int *ans=new int(n+1);
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    minimumCountHelper(n,ans);
    return ans[n];
}
int main(){
    cout<<minimumCount(125);


    return 0;
}