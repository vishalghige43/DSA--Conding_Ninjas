#include<iostream>
#include<stack>

using namespace std;

int main(){
    string str="}}}{";
    stack<char> s1;
    for(int i=0;i<str.length();i++){
        if(!s1.empty()&& str[i]==125 &&s1.top()==123)s1.pop();
        else s1.push(str[i]);
    }
    int count=0;
    while(!s1.empty()){
        if(s1.size()%2==1){
            count=-1;break;
        }
        int c1=s1.top();
        s1.pop();
        int c2=s1.top();
        s1.pop();
        if(c1==c2)count++;
        if(c1!=c2)count+=2;
    }
    

    cout<<count;


    return 0;
}