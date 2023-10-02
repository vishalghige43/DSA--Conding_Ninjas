#include<iostream>
using namespace std;

int knapsnak(int *wi,int *va ,int n,int bag){ 
    if(n<=0 || bag<=0)return 0;
    int acc=INT_MIN;
    if(wi[0]<=bag){
        acc=knapsnak(wi+1,va+1,n-1,bag-wi[0]);
        acc+=va[0];
    }
    int notAcc=knapsnak(wi+1,va+1,n-1,bag);
    return max(acc,notAcc);
}
int knapsnakMemohelper(int *wi,int *va ,int n,int bag,int *ans){
    if(ans[n]!=-1){
        return ans[n];
    }
    if(n<=0 || bag<=0)return 0;
    int acc=INT_MIN;
    if(wi[0]<=bag){
        acc=knapsnak(wi+1,va+1,n-1,bag-wi[0]);
        acc+=va[0];
    }
    int notAcc=knapsnak(wi+1,va+1,n-1,bag);
    ans[n]=max(acc,notAcc);
    return max(acc,notAcc);
}
int knapsnakMemo(int *wi,int *va ,int n,int bag){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    knapsnakMemohelper(wi,va,n,bag,ans);
    return ans[n];
}
int knapsnakDp(int *wi,int *va ,int n,int bag){
    //take 2-d array(remianing weight of bag,wi[i]);
    int *ans=new int[n+1];
    ans[n]=0;
    int bagTemp=bag;
    for(int i=n-1;i>=0;i++){
        
    }



}
int main(){
    int m;
    cin>>m;
    int *wi=new int[m];
    int *va=new int[m];

    for(int i=0;i<m;i++){
        cin>>wi[i];
    }
    for(int i=0;i<m;i++){
        cin>>va[i];
    }
    int bag=0;
    cin>>bag;
    cout<<knapsnak(wi,va,m,bag)<<endl;
    cout<<knapsnakMemo(wi,va,m,bag)<<endl;


    return 0;
}