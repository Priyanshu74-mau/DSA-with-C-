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
    int find(int target,vector<int>&inorder,int start,int end)
    {
        for(int i=start; i<=end; i++ )
        {
            if(inorder[i]==target)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *Tree(vector<int>&preorder,vector<int>&inorder,int index,int instart,int inend)
    {
        if(instart>inend) return NULL;

        TreeNode *root=new TreeNode(preorder[index]);
        int pos=find(preorder[index],inorder,instart,inend);

        root->left=Tree(preorder,inorder,index+1,instart,pos-1);

        root->right=Tree(preorder,inorder,index+(pos-instart)+1,pos+1,inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return Tree(preorder,inorder,0,0,n-1);
    }
};