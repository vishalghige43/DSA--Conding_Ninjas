#include<iostream>
using namespace std;

int wayToMakeCoinChange(int *coins,int n,int value){
    if(n==0)return 0;
    if(value==0)return 1;
    if(value<0)return 0;
    int ans1=wayToMakeCoinChange(coins,n,value-coins[0]);
    int ans2=wayToMakeCoinChange(coins+1,n-1,value);
    return ans1+ans2;
} 
int wayToMakeCoinChangeMemoHelper(int *coins,int n,int value,int **output){
    if(output[n][value]!=-1){
        return output[n][value];
    }
    if(value==0)return 1;
    if(n==0)return 0;
    if(value<0)return 0;
    int ans1=wayToMakeCoinChange(coins,n,value-coins[0]);
    int ans2=wayToMakeCoinChange(coins+1,n-1,value);
    output[n][value]=ans1+ans2;
    return ans1+ans2;
}
int wayToMakeCoinChangeMemo(int *coins,int n,int value){
    int **output=new int*[n+1];
    for(int i=0;i<=n;i++){
        output[i]=new int[value+1];
        for(int j=0;j<=value;j++){
            output[i][j]=-1;
        }
    }
    int ans=wayToMakeCoinChangeMemoHelper(coins,n,value,output);
    return ans;
}
int wayToMakeCoinChangeDp(int *coins,int n,int value){
    int **output=new int*[n+1];
    for(int i=0;i<=n;i++){
        output[i]=new int[value+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=value;j++){
            if(j==0){
                output[i][j]=1;continue;
            }
            if(i==0){
                output[i][j]=0;continue;
            }

            if(j-coins[i-1]<0){
                output[i][j]=output[i-1][j];
            }
            else
            output[i][j]=output[i-1][j]+output[i][j-coins[i-1]];
        }
    }
    return output[n][value];
}
int main(){
    int n;cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int value;
    cin>>value;
    cout<<wayToMakeCoinChangeMemo(arr,n,value)<<endl;
    cout<<wayToMakeCoinChangeDp(arr,n,value);


    return 0;
}