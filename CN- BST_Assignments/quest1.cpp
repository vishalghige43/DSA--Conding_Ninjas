#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
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
    cout<<endl;
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
/*CN-Binary Tree and BST Assignment*/
/*<<<<<<<<<Question 0>>>>>>>>>>>>>>*/
BTNode<int>* duplicateTree(BTNode<int>* root){
    if(!root){return NULL;}
    root->left=duplicateTree(root->left);
    BTNode<int>*temp=new BTNode<int>(root->data);
    temp->left=root->left;
    root->left=temp;
    root->right=duplicateTree(root->right);
    return root;
}
/*<<<<<<<<<Question 1>>>>>>>>>>>>>>*/
/*vector<pair<int,int> >* result=new vector<pair<int,int> >();
map<int,int>* ans;
void pairSum(BTNode<int>* root,int target){
    
    if(!root)return;
    int remainder=target-root->data;
    if(ans->find(remainder)==ans->end()){
        pair<int,int>temp;
        ans[];
    }
    else{
        pair<int,int> temp={remainder,root->data};
        result->push_back(temp);
    }
    pairSum(root->left,target);
    pairSum(root->right,target);
}
void printpairSumAns(){
    for(int i=0;i<result->size();i++){
        cout<<result->at(i).first<<" "<<result->at(i).second<<endl;
    }
}*/
/*<<<<<<<<<Question 2>>>>>>>>>>>>>>*/
int LCA(BTNode<int>* root,int node1,int node2){
    if(!root)return -1;
    if(root->data==node1 ||root->data==node2){
        return root->data;
    }
    
    int leftAns=LCA(root->left,node1,node2);
    int rightAns=LCA(root->right,node1,node2);
    if(leftAns!=-1 && rightAns!=-1){
        return root->data;
    }
    return max(leftAns,rightAns);
}
/*<<<<<<<<<Question 3>>>>>>>>>>>>>>*/
int BstLca(BTNode<int>* root,int node1,int node2){
    if(!root)return -1;
    if(root->data==node1 ||root->data==node2){
        return root->data;
    }
    int leftAns=-1;
    int rightAns=-1;
    if(root->data<node1 && root->data<node2){
        rightAns=BstLca(root->right,node1,node2);
    }
    else if(root->data>node1 && root->data>node2){
        leftAns=BstLca(root->left,node1,node2);
    }
    else {
        leftAns=BstLca(root->left,node1,node2);
        rightAns=BstLca(root->right,node1,node2);
    }
    if(leftAns!=-1 && rightAns!=-1){
        return root->data;
    }
    return max(leftAns,rightAns);
}
/*<<<<<<<<<Question 3>>>>>>>>>>>>>>*/
class largestBstReturn{
    public:
    int minimum;
    int maximum;
    int height;
    bool isBST;
    largestBstReturn(bool isBST=true,int minimum=INT_MAX,int maximum=INT_MIN,int height=0){
        this->isBST=isBST;
        this->maximum=maximum;
        this->minimum=minimum;
        this->height=height;
    }
};
largestBstReturn* helper(BTNode<int>* root){
    if(!root){
        largestBstReturn* ans=new largestBstReturn;
        return ans;
    }
    largestBstReturn* leftAns=helper(root->left);
    largestBstReturn* rightAns=helper(root->right);
    int miniumum=min(root->data,min(leftAns->minimum,rightAns->minimum));
    int maximum=max(root->data,max(leftAns->maximum,rightAns->maximum));
    bool isBST=leftAns->isBST && rightAns->isBST && (leftAns->maximum<root->data) &&(rightAns->minimum>root->data);
    int height=(isBST==true)?max(leftAns->height,rightAns->height)+1:max(leftAns->height,rightAns->height);
    largestBstReturn* ans=new largestBstReturn(isBST,miniumum,maximum,height);
    return ans;
}
int largestBST(BTNode<int>* root){
    return helper(root)->height;
} 
/*<<<<<<<<<Question 4>>>>>>>>>>>>>>*/
int sum(BTNode<int>* root){
    if(!root)return 0;
    int leftAns=sum(root->left);
    int rightAns=sum(root->right);
    return leftAns+rightAns+root->data;
}

void replaceWithSum(BTNode<int>* root){
    int data=sum(root);
    replaceHelper(root,data);
}
void replaceHelper(BTNode<int>* root,int prevData){
    if(!root)return;
    replaceHelper(root->left,prevData);
    int temp=root->data;
    prevData-=temp;
    

}

int main(){
    /*1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1*/
    //bst
    /* 5 3 7 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1 */
    BTNode<int>*root=levelInput();
    levelDisplay(root);
    // cout<<BstLca(root,2,8);
    // duplicateTree(root);
    // levelDisplay(root);
    cout<<largestBST(root);

    return 0;
}