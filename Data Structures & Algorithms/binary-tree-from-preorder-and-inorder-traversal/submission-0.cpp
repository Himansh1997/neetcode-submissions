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
public:
    int preIndex= 0;
    int inIndex= 0;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, long size){
        if(preIndex >= preorder.size()){
            return NULL;
        }
        if(inorder[inIndex] == size){
            inIndex++;
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[preIndex++]);
        root->left= dfs(preorder, inorder, root->val);
        root->right= dfs(preorder, inorder, size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
