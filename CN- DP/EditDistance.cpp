#include<iostream>
#include<cmath>
using namespace std;
int editDistanceDp(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        ans[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        ans[0][j]=j;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=ans[i-1][j-1];
            }
            else {
                int a=ans[i][j-1];
                int b=ans[i-1][j];
                int c=ans[i-1][j-1];
                ans[i][j]=min(a,min(b,c))+1;
            }
        }
    }
    return ans[m][n];
}
int editDistanceMemoHelper(string s,string t,int ** ans){
    int m=s.size();
    int n=t.size();
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    if(s.size()==0 || t.size()==0){
        int ans=max(s.size(),t.size());
        return ans;
    }
    if(s[0]==t[0]){
        return editDistanceMemoHelper(s.substr(1),t.substr(1),ans);
    }
    int a=editDistanceMemoHelper(s,t.substr(1),ans);
    int b=editDistanceMemoHelper(s.substr(1),t,ans);
    int c=editDistanceMemoHelper(s.substr(1),t.substr(1),ans);
    int output=min(a,min(b,c))+1;
    ans[m][n]=output;
    return output;
}
int editDistanceMemo(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            ans[i][j]=-1;
        }
    }
    editDistanceMemoHelper(s,t,ans);
    return ans[m][n];
}
int editDistance(string s,string t){
    if(s.size()==0 || t.size()==0){
        int ans=max(s.size(),t.size());
        return ans;
    }
    if(s[0]==t[0]){
        return editDistance(s.substr(1),t.substr(1));
    }
    int a=editDistance(s,t.substr(1));
    int b=editDistance(s.substr(1),t);
    int c=editDistance(s.substr(1),t.substr(1));
    int output=min(a,min(b,c))+1;
    return output;
}
int main(){
    cout<<editDistanceDp("abcdabcdabcdabcdabcd","axdaxdaxdaxdaxdaxdaxd")<<endl;
    cout<<editDistance("abcdabcdabcdabcdabcd","axdaxdaxdaxdaxdaxdaxd")<<endl;


    return 0;
}