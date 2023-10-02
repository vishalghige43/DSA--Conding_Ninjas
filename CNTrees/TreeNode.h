#include<vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> child;
    TreeNode(T data){
        this->data=data;
    }
    ~TreeNode(){
        for(int i=0;i<child.size();i++){
            delete child[i];
        }
    }
};



