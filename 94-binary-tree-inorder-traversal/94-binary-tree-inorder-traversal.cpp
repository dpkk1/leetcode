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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>res;
        if(!root)
            return res;
        TreeNode *node = root;
        while(true){
            if(node != NULL){
                s.push(node);
                node = node -> left;
            }
            else{
                if(s.size()==0)
                    break;
                node = s.top();
                s.pop();
                res.push_back(node->val);
                node = node -> right;
            }   
        }
        return res;
    }
};