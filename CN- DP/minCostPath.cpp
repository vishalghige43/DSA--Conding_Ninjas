#include<iostream>
using namespace std;
int minCostPathDp(int **arr,int n,int m){
    int **ans=new int*[n];
    for(int i=0;i<n;i++){
        ans[i]=new int[m];
    }
    ans[n-1][m-1]=arr[n-1][m-1];
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1)continue;
            int x=INT_MAX,y=INT_MAX,z=INT_MAX;
            if(i+1<n){
                x=ans[i+1][j];
            }
            if(j+1<m){
                y=ans[i][j+1];
            }
            if(i+1<n && j+1<m){
                z=ans[i+1][j+1];
            }
            ans[i][j]=min(x,min(y,z))+arr[i][j];
        }
    }
    return ans[0][0];
}
int minCostPathHelper(int **arr,int n,int m,int i,int j,int **output){
    if(output[i][j]!=-1){
        return output[i][j];
    }
    if(i==n && j==m){
        return arr[i][j];
    }
    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    if(i!=n){
        x=minCostPathHelper(arr,n,m,i+1,j,output);
    }
    if(j!=m){
        y=minCostPathHelper(arr,n,m,i,j+1,output);
    }
    if(i!=n && j!=m){
        z=minCostPathHelper(arr,n,m,i+1,j+1,output);
    }
    int ans=min(x,min(y,z))+arr[i][j];
    output[i][j]=ans;
    return ans;
}
int minCostPath_2(int **arr,int n,int m){
    int **ans=new int*[n];
    for(int i=0;i<n;i++){
        ans[i]=new int[m];
        for(int j=0;j<m;j++){
            ans[i][j]=-1;
        }
    }
    minCostPathHelper(arr,n-1,m-1,0,0,ans);
    return ans[0][0];
}
int minCostPath(int **arr,int n,int m,int i,int j){
    if(i==n && j==m){
        return arr[i][j];
    }
    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    if(i!=n){
        x=minCostPath(arr,n,m,i+1,j);
    }
    if(j!=m){
        y=minCostPath(arr,n,m,i,j+1);
    }
    if(i!=n && j!=m){
        z=minCostPath(arr,n,m,i+1,j+1);
    }
    int ans=min(x,min(y,z))+arr[i][j];
    return ans;
}
int main(){
    int **arr=new int*[3];
    for(int i=0;i<3;i++){
        arr[i]=new int[3];
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    cout<<minCostPath_2(arr,3,3)<<endl;
    cout<<minCostPathDp(arr,3,3)<<endl;



    return 0;
}