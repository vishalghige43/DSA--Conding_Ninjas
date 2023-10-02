#include<iostream>
using namespace std;
void fiboLoop(int n){
    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n+1;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];
}
int minStepDp(int n){
    int *arr=new int[n+1];
    arr[1]=0;
    arr[0]=0;
    for(int i=2;i<=n;i++){
        int x=arr[i-1];
        int y=INT_MAX;
        int z=INT_MAX;
        if(i%2==0)y=arr[i/2];
        if(i%3==0)z=arr[i/3];
        arr[i]=min(x,min(y,z))+1;
    }
    return arr[n];
}
int minStepHelper(int n,int*list){
    if(list[n]!=-1){
        return list[n];
    }
    if(n<=1){
        return 0;
    }
    int ans2=INT_MAX;
    int ans3=INT_MAX;
    if(n%3==0){
        ans3=minStepHelper(n/3,list);
    }
    if(n%2==0){
        ans2=minStepHelper(n/2,list);
    }
    int ans1=minStepHelper(n-1,list);
    int ans=min(ans1,min(ans2,ans3));
    list[n]=ans+1;
    return ans+1;
}
int minStep(int n){
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    minStepHelper(n,arr);
    return  arr[n];
}
int main(){
    cout<<minStep(9)<<endl;
    cout<<minStepDp(9);


    return 0;
}