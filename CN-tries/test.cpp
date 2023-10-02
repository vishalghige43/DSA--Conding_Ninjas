#include<iostream>
#include<vector>
#include"Trie.h"
using namespace std;

int main(){
    Trie t;
    vector<string> v;
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    for(int i=0;i<v.size();i++)
    t.suffixInsert(v[i]);
    cout<<t.search("e");
    return 0;
}