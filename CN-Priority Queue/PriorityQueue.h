#include<vector>
#include<iostream>
using namespace std;
class PriorityQueue{
    vector<int> pq;
    public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getMin(){
        if(isEmpty())return 0;
        return pq[0];
    }
    int getSize(){
        return pq.size();
    }
    void insert(int data){
        pq.push_back(data);
        int childIndex=pq.size()-1;
        int parentIndex=(childIndex-1)/2;

        while(childIndex>0 && pq[parentIndex]>pq[childIndex]){
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[childIndex];
            pq[childIndex]=temp;
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
        return;
    }
    void remove(){
        if(isEmpty())return;
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftChildIndex=(parentIndex*2)+1;
        int rightChildIndex=(parentIndex*2)+2;
        while(leftChildIndex<pq.size() ){
            int minIndex=parentIndex; 
            if(pq[minIndex]>pq[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            else if(rightChildIndex<pq.size() && pq[minIndex]>pq[rightChildIndex]){
                minIndex=rightChildIndex;
            }
            else{
                break;
            }
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[minIndex];
            pq[minIndex]=temp;

            parentIndex=minIndex;
            leftChildIndex=(parentIndex*2)+1;
            rightChildIndex=(parentIndex*2)+2;
        }
    }
    void display(){
        for(auto i :pq){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};