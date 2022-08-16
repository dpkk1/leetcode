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
    vector<TreeNode*>helper(int start, int end){
        vector<TreeNode*>v;
        if(start > end){
            v.push_back(NULL);
            return v;
        }
        if(start == end){
            v.push_back(new TreeNode(start));
            return v;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*>leftPossibleTrees = helper(start, i-1);
            vector<TreeNode*>rightPossibleTrees = helper(i+1, end);
            for(auto lRoot: leftPossibleTrees){
                for(auto rRoot: rightPossibleTrees){
                    TreeNode *root = new TreeNode(i);
                    root -> left = lRoot;
                    root -> right = rRoot;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};