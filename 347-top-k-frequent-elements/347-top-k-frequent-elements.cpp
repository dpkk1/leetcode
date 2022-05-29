class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(auto i:nums)
            m[i]++;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i:m){
            pq.push({i.second, i.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>v;
        while(!pq.empty()){
            pair<int,int>top = pq.top();
            v.push_back(top.second);
            pq.pop();
        }
        return v;
    }
};