#include<iostream>
#include<stack>

using namespace std;
void ans (stack<int> &s1,stack<int> &s2){
    if(s1.size()==1 || s1.empty())return ;
    int x=s1.top();
    s1.pop();
    ans(s1,s2);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

int main(){
    stack<int> s1;
    s1.push(10);
    s1.push(30);
    s1.push(40);
    s1.push(20);
    s1.push(50);
    s1.push(60);
    stack<int> s2;
    // while(!s1.empty()){
    //     cout<<s1.top()<<" ";
    //     s1.pop();
    // }
    //  cout<<endl;
    // s1.push(10);
    // s1.push(30);
    // s1.push(40);
    // s1.push(20);
    // s1.push(50);
    // s1.push(60);
    ans(s1,s2);
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;




    return 0;
}