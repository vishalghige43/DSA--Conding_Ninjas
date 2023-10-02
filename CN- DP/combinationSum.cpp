#include<iostream>
#include<vector>
#include<set>
using namespace std;
void combinationSumHelper(vector<int>& candidates,int index, int target,vector<int>store,set<vector<int>>*output){
        if(index==candidates.size()){
            if(target==0){
                output->insert(store);
            }
            return;
        }
        if(target<0)return;
        combinationSumHelper(candidates,index+1,target,store,output);
        store.push_back(candidates[index]);
        combinationSumHelper(candidates,index,target-candidates[index],store,output);
    }

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> >ans;
    set<vector<int> > *output=new set<vector<int> >;
    vector<int>store;
    combinationSumHelper(candidates,0,target,store,output);
    for(auto i=output->begin();i!=output->end();++i){
        ans.push_back(*i);
    }
    return ans;  
}



int main(){
    


    return 0;
}