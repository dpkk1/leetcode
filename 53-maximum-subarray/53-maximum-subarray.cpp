class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0, ans=INT_MIN;
        for(int i:nums){
            sum += i;
            if(sum>ans)
                ans = sum;
            if(sum<0)
                sum=0;
        }
        return ans;
    }
};