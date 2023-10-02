#include<iostream>
#include<queue>
#include<math.h>
#include"TreeNode.h"
#include"Pair.h"
using namespace std;

TreeNode <int> *levelInput(){
    int rootData;
    cout<<"Enter Root data : ";
    cin>>rootData;
    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){  
        TreeNode<int>*front=pending.front();
        pending.pop();
        int n;
        cout<<"Enter No of child of "<<front->data<<" : ";
        cin>>n;

        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter "<<i+1<<"th child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            front->child.push_back(child);
            pending.push(child);    
        }
    }
    return root;
}
TreeNode <int> * input(){
    int rootData;
    cout<<"Enter data : ";
    cin>>rootData;
    TreeNode<int>*root=new TreeNode<int>(rootData);
    int n;
    cout<<"Enter no.children : ";
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>*child= input();
        root->child.push_back(child);
    }
    return root;
}
void display(TreeNode<int>*root){
    if(root==NULL)return;
    cout<<root->data<<": ";
    for(int i=0;i<root->child.size();i++){
        cout<<root->child[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->child.size();i++){
        display(root->child[i]);
    }
}
void levelDisplay(TreeNode<int>*root){
    queue<TreeNode<int>*>pending;
    pending.push(root);
    while(pending.size()!=0){
        TreeNode<int>*front=pending.front();
        pending.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->child.size();i++){
            cout<<front->child[i]->data<<" , ";
            pending.push(front->child[i]);
        }
        cout<<endl;
    }
}
int size(TreeNode<int>*root){
    int x=1;
    for(int i=0;i<root->child.size();i++){
        x+=size(root->child[i]);
    }
    return x;
}
int maxTreeNode(TreeNode<int> *root){
    int m=INT_MIN;
    for(int i=0;i<root->child.size();i++){
        m=maxTreeNode(root->child[i]);
    }
    m=max(m,root->data);
    return m; 
}
int height(TreeNode<int> *root){
    int maxHeight=0;
    for(int i=0;i<root->child.size();i++){
        int h=height(root->child[i]);
        maxHeight=max(maxHeight,h);
    }
    return maxHeight+1;
}
void printAtLevel(TreeNode<int> *root,int k){
    if(root==NULL)return;    
    if(k==0){
        cout<<root->data<<" "<<endl;
        return;
    }
    for(int i=0;i<root->child.size();i++){
        printAtLevel(root->child[i],k-1);
    }
}
int leafNodes(TreeNode<int> *root){
    int leafNode=0;
    if(root->child.size()==0)return leafNode+1;
    for(int i=0;i<root->child.size();i++){
        leafNode+=leafNodes(root->child[i]);
    }
    return leafNode;
}
void preOrder(TreeNode<int> *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    for(int  i=0;i<root->child.size();i++){
        preOrder(root->child[i]);
    }
   
}
void postOrder(TreeNode<int> *root){
    if(root==NULL)return;
    for(int  i=0;i<root->child.size();i++){
        postOrder(root->child[i]);
    }
    cout<<root->data<<" ";
}
void deleteTree(TreeNode<int> *root){
    for(int i=0;i<root->child.size();i++){
        deleteTree(root->child[i]);
    }
    delete root;
}
TreeNode<int> *maximun=NULL;
void larNode(TreeNode<int> *root){
    if(root==NULL)return ;
    if((maximun)==NULL)maximun=root;
    else if((maximun)->data<root->data)maximun=root;
    for(int i=0;i<root->child.size();i++){
        larNode(root->child[i]);
    }
}
int largestNode(TreeNode<int> *root){
    larNode(root);
    return maximun->data;
}
int findSum(TreeNode<int> *root){
    if(root==NULL)return 0;
    int sum=root->data;
    for(int i=0;i<root->child.size();i++){
        sum+=findSum(root->child[i]);
    }
    return sum;
}
int countNodes(TreeNode<int> *root){
    if(root==NULL)return 0;
    int nodes=0;
    for(int i=0;i<root->child.size();i++){
        nodes+=countNodes(root->child[i]);
    }
    return nodes+1;
}
bool check(TreeNode<int>*n1,TreeNode<int>*n2){
    if(n1->data!=n2->data)return false;
    if(n1->child.size()!=n2->child.size())return false;
    for(int i=0;i<n1->child.size();i++){
        return check(n1->child[i],n2->child[i]);
    }
    return true;
}
/*TreeNode<int> *lar=NULL;
void findLar(TreeNode<int> *root,int n){
    if(root->data>n && (lar==NULL || root->data<lar->data))lar=root;
    for(int i=0;i<root->child.size();i++){
        findLar(root->child[i],n);
    }
}*/
void changeToDepth(TreeNode<int> *root,int depth){
    root->data=depth;
    for(int i=0;i<root->child.size();i++){
        changeToDepth(root->child[i],++depth);
        depth--;
    }

}
TreeNode<int>* findLar(TreeNode<int> *root,int n){
    TreeNode<int> *ans=NULL;
    if(ans==NULL && root->data>n)ans=root;
    for(int i=0;i<root->child.size();i++){
        TreeNode<int> *temp=findLar(root->child[i],n);
        if(temp!=NULL && temp->data>n && (ans==NULL || temp->data< ans->data)){
            ans=temp;
        }   
    }    
    return ans;
} 

TreeNode<int> *maxNode=NULL;
int maxSum=0;
void maxChild(TreeNode<int> *root){
    if(root==NULL)return;
    if(maxNode==NULL)maxNode=root;
    int sum=root->data;
    for(int i=0;i<root->child.size();i++){
        sum+=root->child[i]->data;
    }
    if(maxSum<sum){
        maxNode=root;
        maxSum=sum;
    }
    for(int i=0;i<root->child.size();i++){
        maxChild(root->child[i]);
    }
}
int maxChildSum(TreeNode<int> *root){
    maxChild(root);
    return maxNode->data;
}
int main(){
    cout<<endl;
    TreeNode<int> *root=levelInput();

    // cout<<endl;
    // levelDisplay(root);

    cout<<endl;

    // cout<<endl;
    // cout<<endl;
    cout<<endl;
    preOrder(root);
    cout<<endl;
    changeToDepth(root,0);
    // levelDisplay(root);
    preOrder(root);
    cout<<endl;

    /*
    TreeNode<int> *lar= findLar(root,51);
    if(lar!=NULL)
    cout<<lar->data<<endl;
    else{
        cout<<"NULL";
    }
    */

    // TreeNode<int> *root2=levelInput();

    // cout<<endl;

    // cout<<endl;
    // preOrder(root2);
    // cout<<endl;
    // postOrder(root2);
    // cout<<endl;

    // cout<<check(root,root2)<<endl;


    // cout<<maxChildSum(root)<<endl;
    // cout<<leafNodes(root)<<endl;
    // cout<<countNodes(root);
    // cout<<largestNode(root)<<endl;
    // cout<<findSum(root)<<endl;
    


    // // cout<<size(root)<<endl;
    // // cout<<maxTreeNode(root)<<endl;

    // cout<<height(root)<<endl;

    // delete root;
    

    return 0;
}