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
    bool PathSum(TreeNode *root, int Tsum)
    {
        if(!root) return 0;
        
        if(!root->left && !root->right && Tsum==root->val)
        {
            return 1;
        }

        return PathSum(root->left,Tsum-root->val) ||
               PathSum(root->right,Tsum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return PathSum(root,targetSum);
    }
};