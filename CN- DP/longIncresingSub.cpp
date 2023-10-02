#include<iostream>
using namespace std;
int longIncreSub(int *input,int n){
    int *output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]>input[i]){
                continue;
            }
            else{
                int ans=output[j]+1;
                if(ans>output[i]){
                    output[i]=ans;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,output[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longIncreSub(arr,n);

    return 0;
}