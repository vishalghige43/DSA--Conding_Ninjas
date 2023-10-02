#include<iostream>
using namespace std;
int lootHouse(int *house,int n){
    if(n<=0){
        return 0;
    }
    int acc=house[0];
    acc+=lootHouse(house+2,n-2);
    int notAcc=lootHouse(house+1,n-1);
    return max(acc,notAcc);
}
int lootHouseDp(int *house,int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=house[0];
    for(int i=2;i<=n;i++){
        int a=ans[i-1];
        int b=ans[i-2]+house[i-1];
        ans[i]=max(a,b);
    }
    return ans[n];
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lootHouse(arr,n);
    return 0;
}