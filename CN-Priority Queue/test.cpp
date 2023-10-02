#include<iostream>
#include"PriorityQueue.h"
using namespace std;

int main(){
    PriorityQueue q1;
    q1.insert(10);
    q1.insert(12);
    q1.insert(13);
    q1.insert(11);
    q1.insert(1);
    q1.display();
    q1.remove();
    q1.display();
    q1.remove();
    q1.display();

    return 0;
}