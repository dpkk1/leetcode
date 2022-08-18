class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int>m;
        int n = arr.size();
        priority_queue<pair<int,int>>pq;
        for(auto i:arr)
            m[i]++;
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        int ele=0, ans=0;
        while(!pq.empty()){
            ele += pq.top().first;
            pq.pop();
            ans++;
            
            if(ele >= n/2)
                return ans;
        }
        return 0;
    }
};