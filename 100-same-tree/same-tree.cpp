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
    bool identical(TreeNode *p, TreeNode *q)
    {   
        if(!p && !q) return 1;

        if(!q || !p) return 0;
        
        if(p->val != q->val) return 0;
    
        return identical(p->left,q->left) && identical(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return identical(p,q);
    }
};