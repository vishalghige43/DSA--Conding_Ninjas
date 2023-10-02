#include<iostream>
#include<string>
using namespace std;
int comSubSq(string s,string t){
    if(s.length()==0 || t.length()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1+ comSubSq(s.substr(1),t.substr(1));
    }
    int a=comSubSq(s.substr(1),t);
    int b=comSubSq(s,t.substr(1));
    int c=comSubSq(s.substr(1),t.substr(1));
    
    return max(a,max(b,c));
}
int comSubSqDp(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        ans[i][0]=0;
    }
    for(int j=0;j<=n;j++){
        ans[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=1+ans[i-1][j-1];
            }
            else {
                int a=ans[i][j-1];
                int b=ans[i-1][j];
                int c=ans[i-1][j-1];
                ans[i][j]=max(a,max(b,c));
            }
        }
    }
    return ans[m][n];
}
int main(){
    cout<<comSubSq("xyz","zxay")<<endl;
    cout<<comSubSqDp("xyz","zxay");


    return 0;
}