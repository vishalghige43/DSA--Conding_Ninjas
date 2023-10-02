#include<iostream>
#include<vector>
using namespace std;
void heapSorting(int *arr,int n){
    for(int i=1;i<n;i++){
        int childIndex=i;
        int parentIndex=(childIndex-1)/2;
        while(childIndex>0 && arr[childIndex]<arr[parentIndex]){
            int temp=arr[childIndex];
            arr[childIndex]=arr[parentIndex];
            arr[parentIndex]=temp;
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
    }
    int size=n;
    while(size>1){
        int temp=arr[size-1];
        arr[size-1]=arr[0];
        arr[0]=temp;
        size--;
        int parentIndex=0;
        int leftChildIndex=(parentIndex*2)+1;
        int rightChildIndex=(parentIndex*2)+2;
        while(leftChildIndex<size){
            int minIndex=parentIndex;
            if(arr[minIndex]>arr[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<size && arr[minIndex]>arr[rightChildIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp=arr[minIndex];
            arr[minIndex]=arr[parentIndex];
            arr[parentIndex]=temp;

            parentIndex=minIndex;
            leftChildIndex=(parentIndex*2)+1;
            rightChildIndex=(parentIndex*2)+2;
        }
    }
}
int main(){
    int arr[5]={1,5,2,8,0};
    for(auto x: arr)
    cout<<x<<" ";
    cout<<endl;
    heapSorting(arr,5);
    for(auto x: arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}