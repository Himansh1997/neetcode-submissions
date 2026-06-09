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
    int maxDepth(TreeNode* root) {
       if(root == NULL){
        return 0;
       }
       stack<pair<TreeNode*, int>> stack;
       stack.push({root, 1});

       int count= 0;

       while(!stack.empty()){
        pair<TreeNode*, int> current= stack.top();
        stack.pop();

        TreeNode* node= current.first;
        int depth= current.second;

        if(node != NULL){
            count= max(count, depth);
            if(node->left){
                stack.push({node->left, depth + 1});
            }
            if(node->right){
                stack.push({node->right, depth + 1});
            }
        }
       }
       return count;
    }
};
