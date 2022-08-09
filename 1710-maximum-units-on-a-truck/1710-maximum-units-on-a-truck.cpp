class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b){
           return a[1]>b[1]; 
        });
        int ans=0;
        for(auto i:boxTypes){
            if(truckSize <= 0)
                return ans;
            ans += (min(truckSize, i[0])*i[1]);
            truckSize -= i[0];
        }
        return ans;
    }
};