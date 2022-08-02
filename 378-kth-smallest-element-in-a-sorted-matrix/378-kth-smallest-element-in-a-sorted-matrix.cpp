class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        priority_queue<int>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                q.push(m[i][j]);
                if(q.size()>k)
                    q.pop();
            }
        }
        return q.top();
    }
};