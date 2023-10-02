#include<iostream>
#include<queue>
#include<math.h>
#include<utility>
#include"BinaryTreeNode.h"
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
int sum(BTNode<int> *root){
    if(!root)return 0;
    int lsum=sum(root->left);
    int rsum=sum(root->right);
    return lsum+rsum+root->data;
}
pair<int,bool> balancedTreeHelper(BTNode<int> *root){
    if(!root){
        pair<int,bool>ans;
        ans.first=0;
        ans.second=true;
        return ans;
    }
    pair<int,bool> lAns=balancedTreeHelper(root->left);
    pair<int,bool> rAns=balancedTreeHelper(root->right);

    int height=max(lAns.first,rAns.first)+1;
    bool isBalanced=lAns.second && rAns.second?true : false;
    if(isBalanced){
        if(abs(lAns.first-rAns.first)>1)isBalanced=false;
    }

    pair<int,bool> ans;
    ans.first=height;
    ans.second=isBalanced;
    return ans;
}
bool balancedTree(BTNode<int> *root){
    pair<int,bool> ans=balancedTreeHelper(root);
    return ans.second;
}
BTNode<int> *removeLeaf(BTNode<int> *root){
    if(!root)return NULL;
    if(!root->left && !root->right)return NULL;
    BTNode<int>*lAns=removeLeaf(root->left);
    BTNode<int>*rAns=removeLeaf(root->right);

    root->left=lAns;
    root->right=rAns;
    return root;
}

int main(){
    /*
    1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
    */
    // BTNode<int> *root=levelInput();
    // cout<<endl;
    // levelDisplay(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // root=removeLeaf(root);
    // cout<<endl;
    // levelDisplay(root);
    // cout<<endl;

    // cout<<endl;
    

    return 0;
}