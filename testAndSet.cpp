#include<iostream>
using namespace std;
bool testAnsSet(bool *ptr){
    bool old=*ptr;
    *ptr =true;
    cout<<*ptr<<endl;
    return old;
}
int main(){

    bool lock=false;
    bool *ptr=&lock;
    cout<<"prev :"<<lock<<endl;
    cout<<testAnsSet(&lock)<<endl;
    cout<<"new :"<<lock<<endl;
    
    return 0;
}