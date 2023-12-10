#include<iostream>
#include"graph.h"
using namespace std;
    
int main(){
    graph g1(6,6);
    g1.input();
    g1.BFS();
    g1.DFS();
    cout<<g1.hasPath(0,3)<<endl;;
    
    return 0;
}