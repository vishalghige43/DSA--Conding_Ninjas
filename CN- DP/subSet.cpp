#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printAns(vector < vector < int > > & ans) {
  cout << "The unique subsets are " << endl;

  for (int i = 0; i < ans.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]"<<endl;
  }
  cout <<endl;
}

void subsetsWithDupHelper(vector<int>& nums,int index,vector<int>storage,set<vector<int> >*output) {
    if(index==nums.size()){
        sort(storage.begin(),storage.end());
        output->insert(storage);
        return;
    }
    subsetsWithDupHelper(nums,index+1,storage,output);
    storage.push_back(nums[index]);
    subsetsWithDupHelper(nums,index+1,storage,output);
}
vector<vector<int> >subsetsWithDup(vector<int>& nums){
    vector<vector<int> >ans;
    set<vector<int> > *output=new set<vector<int> >;
    vector<int>storage;
    subsetsWithDupHelper(nums,0,storage,output);
    for(auto i=output->begin();i!=output->end();++i){
        ans.push_back(*i);
    }
    return ans;    
}

int main(){
   
    vector < int > nums ;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector < vector < int > > ans =subsetsWithDup(nums);
    printAns(ans);


    return 0;
}