#include<iostream>
using namespace std;
#include"BinaryTreeNode.h"
class BST{
   BTNode<int>* root;
   bool findHelper(int data, BTNode<int>* root){
      if(!root)return false;
      if(root->data==data)return true;
      else if(data<root->data)return findHelper(data,root->left);
      else return findHelper(data,root->right);
   }
   BTNode<int>* insertHelper(BTNode<int>* root,int data){
      if(!root){
         BTNode<int>*newNode=new BTNode<int>(data);
         return newNode;
      }
      if(data<root->data){
         root->left=insertHelper(root->left,data);
      }
      else root->right=insertHelper(root->right,data);
      return root;
   }
   BTNode<int>* popHelper(BTNode<int>* root,int data){
      if(!root)return NULL;
      if(data<root->data){
         root->left=popHelper(root->left,data);
      }
      else if(data>root->data){
         root->right=popHelper(root->right,data);
      }
      else{
         if(!root->right && !root->left){
            delete root;
            return  NULL;
         }
         else if(!root->right){
            BTNode<int>*temp=root->left;
            root->left=NULL;
            delete root;
            return temp;
         }
         else if(!root->left){
            BTNode<int>*temp=root->right;
            root->right=NULL;
            delete root;
            return temp;
         }
         else{
            BTNode<int>*temp=root->right;
            while(temp->left){
               temp=temp->left;
            }
            int rightMin=temp->data;
            root->data=rightMin;
            root->right=popHelper(root->right,rightMin);
            return root;
         }
      }
   }
   void levelDisplay(BTNode<int> *root){
    if(!root)return;
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
   public:
   BST(){
    root=NULL;
   }
   ~BST(){
    delete root;
   }
   bool find(int data){
      return findHelper(data,root);
   }
   void insert(int data){
      this->root=insertHelper(root,data);
   }
   void pop(int data){
      this->root=popHelper(root,data);
   }
   void print(){
      levelDisplay(root);
   }
   
};