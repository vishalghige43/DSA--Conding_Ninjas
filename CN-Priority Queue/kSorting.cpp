#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void kSortedArray(int *input,int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        input[j]=pq.top();
        pq.pop();
        j++;
        pq.push(input[i]);
    }
    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}
void kMinimum(int *input,int n,int k){
    vector<int> ans;
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++){
        if(input[i]<pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main(){
    int arr[]={10,0,7,5,9,2,1};
    kMinimum(arr,7,1);

    return 0;
}