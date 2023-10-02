#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> mergeKSorted(vector<vector<int> >& arr){
    vector<int> sorted;
    priority_queue<pair<int,pair<int,int> > >pq;
    for(int i=0;i<arr.size() ;i++){
       pair<int,pair<int,int> > ans;
       ans.first=arr[i][0];
       ans.second.first=i;
       ans.second.second=0;
        pq.push(ans);
    }
    while(!pq.empty()){ 
        sorted.push_back(pq.top().first);
        int i=pq.top().second.first;
        int j=(pq.top().second.second)+1;
        if(j<arr[i].size()){
            pair<int,pair<int,int> > ans;
            ans.first=arr[i][j];
            ans.second.first=i;
            ans.second.second=j;
            pq.push(ans);
        }
           
    }
    return sorted;
}

int main(){
   
    vector<vector<int> >input{{},{2,4,6,8,10,12},{14,15}};
    vector<int>num1{1,3,5,7,9,11,13};
    vector<int> ans=mergeKSorted(input);
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}