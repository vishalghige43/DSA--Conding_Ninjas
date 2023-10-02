#include<iostream>
using namespace std;
int stairCase(int n){
    if(n==0){
        return 1;
    }
    int x=stairCase(n-1);
    int y=0,z=0;
    if(n>1){
        y=stairCase(n-2);
    }
    if(n>2){
        z=stairCase(n-3);
    }
    return x+y+z;
}
int stairCaseHelper(int n,int *ans){
    if(ans[n]!=-1){
        return ans[n];
    }
    if(n==0){
        return 1;
    }
    int x=stairCase(n-1);
    int y=0,z=0;
    if(n>1){
        y=stairCase(n-2);
    }
    if(n>2){
        z=stairCase(n-3);
    }
    ans[n]=x+y+z;
    return ans[n];
}
int stairCase_2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    stairCaseHelper(n,ans);
    return ans[n];
}
int stairCaseDp(int n){
    int *ans=new int[n+1];
    ans[0]=1;
    for(int i=1;i<=n;i++){
        int x=ans[i-1];
        int y=0,z=0;
        if(i>1){
            y=ans[i-2];
        }
        if(i>2){
            z=ans[i-3];
        }
        ans[i]=x+y+z;
    }
    return ans[n];
}
int main(){
    cout<<stairCase(10)<<endl;
    cout<<stairCase_2(10)<<endl;
    cout<<stairCaseDp(10);


    return 0;
}