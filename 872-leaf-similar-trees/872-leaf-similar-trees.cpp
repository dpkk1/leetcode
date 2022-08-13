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
    
    void inorder(TreeNode* root, vector<int>&ans){
        if(root->left)
            inorder(root->left, ans);
        if(!root->left && !root->right)
            ans.push_back(root->val);
        if(root->right)
            inorder(root->right, ans);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);
        return (nums1==nums2);
    }
};