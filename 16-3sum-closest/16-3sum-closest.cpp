class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i=0;
        int temp = nums[0]+nums[1]+nums[2];
        while(i<nums.size()-2){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(temp-target))
                    temp = sum;
                else if(sum>target)
                    k--;
                else if(sum<target)
                    j++;
                else
                    return target;
            }
            i++;
        }
        return temp;
    }
};