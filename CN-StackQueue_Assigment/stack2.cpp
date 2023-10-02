#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> s1;
    string str="[{(a+b)+c+d}]";
    bool ans=false;
    int count=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==42||str[i]==93||str[i]==125){
            if(count<2){
                ans=true;
                break;
            }
            while(s1.top()==str[i]+1||s1.top()==str[i]+2){
                s1.pop();
            }
            s1.pop();
            count=0;
        }
        else{
            count++;
            if(str[i]==41||str[i]==91||str[i]==123){
                count=0;
            }
            s1.push(str[i]);
        }
    }
    cout<<ans;

    return 0;
}