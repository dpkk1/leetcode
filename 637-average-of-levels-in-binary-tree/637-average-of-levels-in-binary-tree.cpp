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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        if(!root)
            return {0.0};
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            double sum=0;
            for(int i=0; i<n; i++){
                TreeNode *temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            double avg = (sum*1.0)/n;
            res.push_back(avg);
        }
        return res;
    }
};