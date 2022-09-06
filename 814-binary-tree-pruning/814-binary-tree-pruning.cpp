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
    int helper(TreeNode* &root){
        if(!root)
            return 0;
        int leftSubTreeOnes = helper(root->left);        
        int rightSubTreeOnes = helper(root->right);
        if(leftSubTreeOnes == 0)
            root->left = NULL;
        if(rightSubTreeOnes == 0)
            root->right = NULL;
        return leftSubTreeOnes+rightSubTreeOnes+(root->val);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(helper(root) == 0)
            return NULL;
        return root;
    }
};