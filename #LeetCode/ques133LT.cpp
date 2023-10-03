//question: 94. Binary Tree Inorder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorderTraversalHelper(vector<int> &ans,TreeNode* root) {
        if(root==NULL)return;
        inorderTraversalHelper(ans,root->left);
        ans.push_back(root->val);
        inorderTraversalHelper(ans,root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversalHelper(ans,root);
        return ans ;
    }
};