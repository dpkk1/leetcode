class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int low=0, high=n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]==t)
                return mid;
            else if(nums[mid] > t)
                high = mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
};