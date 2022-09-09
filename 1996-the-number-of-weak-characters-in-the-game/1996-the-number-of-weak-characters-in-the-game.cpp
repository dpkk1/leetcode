class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(), pro.end(), [](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        // for(auto i:pro)
        //     for(auto k:i)
        //         cout<<k<<" ";
        int n = pro.size(), maxi=INT_MIN, ans=0;
        for(int i=n-1; i>=0; i--){
            if(maxi>pro[i][1]) ans++;
            maxi = max(maxi, pro[i][1]);
        }            
        return ans;
    }
};