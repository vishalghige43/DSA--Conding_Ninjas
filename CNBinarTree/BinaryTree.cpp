#include<iostream>
#include"BinaryTreeNode.h"
#include<queue>
#include<vector>
#include<utility>
using namespace std;

void display(BTNode<int> *root){
    if(root==NULL)return;
    cout<<root->data<<" : ";
    if(root->left)cout<<"L"<<root->left->data<<" ";
    if(root->right)cout<<"R"<<root->right->data<<" ";
    cout<<endl;
    display(root->left);
    display(root->right);
}
BTNode<int> *takeInput(){
    int data;
    cout<<"Enter data : ";
    cin>>data;
    if(data==-1)return NULL;
    BTNode<int> *root=new BTNode<int>(data);
    BTNode<int> *left=takeInput();
    BTNode<int> *right=takeInput();
    root->left=left;
    root->right=right;
    return root;
}
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
int countNode(BTNode<int> *root){
    if(root==NULL)return 0;
    return countNode(root->left)+countNode(root->right)+1;
}
BTNode<int>* buildTreeHelper(int *pre,int *in,int preS,int preE,int inS,int inE ){
    if(inS>inE)return NULL;
    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;break;
        }
    }
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rPreS=lPreE+1;
    int rPreE=preE;
    int rInS=rootIndex+1;
    int rInE=inE;
    BTNode<int>* root=new BTNode<int>(rootData);
    root->left=buildTreeHelper(pre,in,lPreS,lPreE,lInS,lInE);
    root->right=buildTreeHelper(pre,in,rPreS,rPreE,rInS,rInE);
    return root;
}

BTNode<int>* buildTree(int *pre, int *in, int size){
    return buildTreeHelper(pre,in,0,size-1,0,size-1);
}
BTNode<int>* postBuildTreeHelper(int *post,int *in,int postS,int postE,int inS,int inE){
    if(inS>inE)return NULL;
    int rootData=post[postE];
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }

    int lInS=inS;
    int lInE=rootIndex-1;
    int lPosS=postS;
    int lPosE=lInE-lInS+lPosS;
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPosS=lPosE+1;
    int rPosE=postE-1;

    BTNode<int> *root=new BTNode<int>(rootData);
    root->left=postBuildTreeHelper(post,in,lPosS,lPosE,lInS,lInE);
    root->right=postBuildTreeHelper(post,in,rPosS,rPosE,rInS,rInE);

    return root;
}
BTNode<int>* postBuildTree(int *post, int *in, int size){
    return postBuildTreeHelper(post,in,0,size-1,0,size-1);
}


// int height(BTNode<int> *root){
//     if(root==NULL)return 0;
//     return 1+height(root->left)+height(root->right);
// }
// int diameter(BTNode<int> *root){
//     if(root==NULL)return 0;
//     int o1=height(root->left)+height(root->right);
//     int o2=diameter(root->left);
//     int o3=diameter(root->right);
//     return max(o1,max(o2,o3));
// }
pair <int ,int> maxDiameter(BTNode<int> *root){
    pair<int ,int> ans;
    ans.first=0;
    ans.second=0;
    if(root==NULL)return ans;
    pair<int,int> lAns=maxDiameter(root->left);
    pair<int,int> rAns=maxDiameter(root->right);
    int lh=lAns.first;
    int ld=lAns.second;
    int rh=rAns.first;
    int rd=rAns.second;

    int h=1 + max(lh,rh);
    int d=max(lh+rh,max(rd,ld));
    ans.first=h;
    ans.second=d;
    return ans;
}
int diameter(BTNode<int> *root){
    pair <int ,int> ans=maxDiameter(root);
    int x=ans.second;
    return x;

}

pair<int,int> minMax(BTNode<int> *root){
    if(root==NULL){
        pair<int ,int> ans;
        ans.first=INT_MAX;
        ans.second=INT_MIN;
        return ans;
    }
    pair<int ,int> ans;
    ans.first=root->data;
    ans.second=root->data;
    pair<int,int> lAns=minMax(root->left);
    pair<int,int> rAns=minMax(root->right);
    
    int lmin=lAns.first;
    int lmax=lAns.second;
    int rmin=rAns.first;
    int rmax=rAns.second;

    ans.first=min(ans.first,min(lmin,rmin));
    ans.second=max(ans.second,max(lmax,rmax));
    return ans;
}





int main(){
    /*BTNode<int> *root=new BTNode<int>(1);
    root->left=new BTNode<int>(2);
    root->right=new BTNode<int>(3);*/
    //tree=
    /*
    1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
    */
    // int post[]={4,5,2,8,9,6,7,3,1};
    // int pre[]={1,2,4,5,3,6,8,9,7};
    // int in[]={4,2,5,1,8,6,9,3,7};
    // BTNode<int> *root=postBuildTree(post,in,9);
    // BTNode<int> *root2=buildTree(pre,in,9);
    // cout<<endl;
    // levelDisplay(root);
    // cout<<endl;
    // levelDisplay(root2);
    BTNode<int>* root=levelInput();
    cout<<endl;
    inOrder(root);


    cout<<endl;
    pair<int,int>ans=minMax(root);
    cout<<ans.first<<"  ";
    cout<<ans.second<<endl;

    
    // cout<<diameter(root);

    // cout<<countNode(root);

    return 0;
}