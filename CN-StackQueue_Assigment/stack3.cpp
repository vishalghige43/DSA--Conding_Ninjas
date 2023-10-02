#include<iostream>
#include<vector>
using namespace std;

int maxIndex(const vector<int> &v,int k){
    int x=0;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]>k){
            return x+1;
        }
        x++;
    }
    return x+1;
}
int main(){
    vector<int>v;
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(100);
    v.push_back(90);
    v.push_back(75);
    v.push_back(80);
    v.push_back(120);
    vector<int> ans;
    vector<int> s;
    int c=1;
    for(int i=0;i<v.size();i++){
        if(s.size()==0 || v[i]<s[s.size()-1]){
            c=1;
        }
        else if(v[i]==s[s.size()-1]){
            c++;
        }
        else{
            c=maxIndex(s,v[i]);   
        }
        s.push_back(v[i]);
        ans.push_back(c);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;





    return 0;
}