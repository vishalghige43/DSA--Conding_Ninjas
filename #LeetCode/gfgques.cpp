//question: Left View of Binary Tree
void leftViewHelper(Node *root,vector<int>& ans,int h,int& maxH){
    if(!root)return ;
    if(maxH<h){
        ans.push_back(root->data);
        maxH=h;
    }
    leftViewHelper(root->left,ans,h+1,maxH);
    leftViewHelper(root->right,ans,h+1,maxH);
}
vector<int> leftView(Node *root)
{
    vector<int>ans;
    int maxH=-1;
    leftViewHelper(root,ans,0,maxH);
    return ans;
}