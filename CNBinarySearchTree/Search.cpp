#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

BTNode<int> *levelInput(){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    if(data==-1)return NULL;
    queue<BTNode<int>*> pending;
    BTNode<int> *root=new BTNode<int>(data);
    pending.push(root);
    while(pending.size()){
        BTNode<int> *front=pending.front();
        pending.pop();
        int left;
        cout<<"Enter "<<front->data<<"th Left Child Data : ";
        cin>>left;
        if(left!=-1){
            BTNode<int> *leftChild=new BTNode<int>(left);
            front->left=leftChild;
            pending.push(leftChild);
        }
        int right;
        cout<<"Enter "<<front->data<<"th right Child Data : ";
        cin>>right;
        if(right!=-1){
            BTNode<int> *rightChild=new BTNode<int>(right);
            front->right=rightChild;
            pending.push(rightChild);
        }
    }
    return root;
}
void levelDisplay(BTNode<int> *root){
    if(root==NULL)return;
    queue<BTNode<int> *>pending;
    pending.push(root);
    while(pending.size()){
        BTNode<int>* front=pending.front();
        pending.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<"L"<<front->left->data<<" ";
            pending.push(front->left);
        }
        if(front->right){
            cout<<"R"<<front->right->data;
            pending.push(front->right);
        }
        cout<<endl;
    }
    cout<<endl;
}
void inOrder(BTNode<int> *root){
    if(root==NULL)return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
BTNode<int>* find(BTNode<int>* root,int target){
    if(!root)return NULL;
    if(root->data==target){
        return root;
    }
    else if(root->data>target){
        return find(root->left,target);
    }
    else{
        return find(root->right,target);
    }
}
void printRange(BTNode<int>* root,int s,int g){
    if(!root)return ;
    if(root->data<=g &&root->data>=s){
        cout<<root->data<<"  ";
        printRange(root->left,s,g);
        printRange(root->right,s,g);
    }
    else if(root->data>g)
       printRange(root->left,s,g);
    else 
        printRange(root->right,s,g);
    return;
}

class  isBSTReturn{
    public:
    int minimum;
    int maximum;
    bool isBST;
    isBSTReturn(bool isBST=true,int minimum=INT_MAX,int maximum=INT_MIN){
        this->minimum=minimum;
        this->maximum=maximum;
        this->isBST=isBST;
    }
};
isBSTReturn isBSTHelper(BTNode<int>* root){
    if(!root){
        isBSTReturn ans;
        return ans;
    }
    isBSTReturn left=isBSTHelper(root->left);
    isBSTReturn right=isBSTHelper(root->right);
    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.maximum));
    bool isBSTFinal=left.isBST && right.isBST && (left.maximum<root->data) &&(right.minimum>root->data);
    isBSTReturn ans(isBSTFinal,minimum,maximum);
    return ans;
}
bool isBST(BTNode<int>* root){
    if(!root)return true;
    else return isBSTHelper(root).isBST;
}
bool isBST2(BTNode<int>* root,int min=INT_MIN,int max=INT_MAX){
    if(!root)return true;
    if(root->data>max || root->data<min)return false;
    bool left=isBST2(root->left,min,root->data-1);
    bool right=isBST2(root->right,root->data,max);
    return left && right;
}
BTNode<int>*arrInput(const vector<int>& arr,int s,int e){
    if(s>e){
        BTNode<int>* leaf=NULL;
        return leaf;
    }
    int mid=(s+e)/2;
    BTNode<int>* root=new BTNode<int>(arr[mid]);
    BTNode<int>* leftNode=arrInput(arr,s,mid-1);
    BTNode<int>* rightNode=arrInput(arr,mid+1,e);
    root->left=leftNode;
    root->right=rightNode;
    return root;
}
vector<int>* findPath(BTNode<int>* root,int target){
    if(!root)return NULL;
    if(root->data==target){
        vector<int>* ans=new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector<int>* leftAns=findPath(root->left,target);
    if(leftAns){
        leftAns->push_back(root->data);
        return leftAns;
    }
    vector<int>* rightAns=findPath(root->right,target);
    if(rightAns){
        rightAns->push_back(root->data);
        return rightAns;
    }
    return NULL;
}
//TODO
/* pair<LLNode<int>,LLNode<int>> List(BTNode<int>* root){
    if(!root){
        pair<>
        return NULL;
        }
    LLNode<int> leftHead=List(root->left).first;
    LLNode<int> leftTail=List(root->left).second;
    LLNode<int> rightHead=List(root->right).first;
    LLNode<int> rightTail=List(root->right).second;

}*/
int main(){
    /*
    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    */
   //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
   BTNode<int>* root=levelInput();
    cout<<endl;
    levelDisplay(root);
    // BTNode<int>* node=find(root,11);
    // if(find(root,5)!=NULL){
    //     cout<<find(root,5)->data;
    // }
    // else{
    //     cout<<"NULL";;
    // }
    // noOfNode(root,2,8);
    // printRange(root,3,7);
    // cout<<isBST2(root)<<endl;
    /*vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    // arr.push_back();
    BTNode<int>* root=arrInput(arr,0,arr.size()-1);
    levelDisplay(root);*/

    vector<int>* path=findPath(root,9);
    for(int i=0;i<path->size();i++){
        cout<<path->at(i)<<"  ";
    }
    cout<<endl;
    
}
