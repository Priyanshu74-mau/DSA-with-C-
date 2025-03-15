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
    int find(vector<int>&inorder,int target,int start,int end)
    {
        for(int i=start; i<=end; i++)
        {
            if(inorder[i]==target)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *Tree(vector<int>&inorder,vector<int>&postorder,int instart,int inend,int &index)
    {
        if(instart>inend) return NULL;

        TreeNode *root=new TreeNode(postorder[index]);
        int pos=find(inorder,postorder[index],instart,inend);
        index--;

        root->right=Tree(inorder,postorder,pos+1,inend,index);

        root->left=Tree(inorder,postorder,instart,pos-1,index);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int index=n-1;
        return Tree(inorder,postorder,0,n-1,index);
    }
};