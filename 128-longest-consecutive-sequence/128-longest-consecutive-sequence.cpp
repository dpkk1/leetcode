class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        if(nums.size() == 0)
            return 0;
        for(auto i:nums)
            m[i]++;
        int curr=1, ans=1;
        nums.clear();
        for(auto i:m)
            nums.push_back(i.first);
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] == nums[i]+1){
                curr++;
                ans = max(curr, ans);
            }
            else
                curr=1;
        }
        return ans;
    }
};