class Solution {    
    void findCombination(int ind, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds); //pick the element, call at that index only 
            ds.pop_back();
        }
        findCombination(ind+1,target, arr, ans, ds); //not picking this element, move to index element
    }    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans,ds);
        return ans;
    }
};

//time compplexity: O(2^t * k)
//space complexity: O(k * x) 