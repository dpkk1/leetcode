class Solution {
public:
    vector<int>NSL(vector<int>&v){
        stack<pair<int,int>>s;
        vector<int>ans;
        for(int i=0; i<v.size(); i++){
            if(s.size()==0)
                ans.push_back(-1);
            else if(s.size()>0 && s.top().first<v[i])
                ans.push_back(s.top().second);
            else if(s.size()>0 && s.top().first >= v[i]){
                while(s.size()>0 && s.top().first >= v[i])
                    s.pop();
                if(s.size()==0)
                    ans.push_back(-1);
                else
                    ans.push_back(s.top().second);
            }
            s.push({v[i],i});
        }
        return ans;
    }
    
    vector<int>NSR(vector<int>&v){
        stack<pair<int,int>>s;
        vector<int>ans;
        int n = v.size();
        for(int i=n-1; i>=0; i--){
            if(s.size()==0)
                ans.push_back(n);
            else if(s.size()>0 && s.top().first<v[i])
                ans.push_back(s.top().second);
            else if(s.size()>0 && s.top().first >= v[i]){
                while(s.size()>0 && s.top().first >= v[i])
                    s.pop();
                if(s.size()==0)
                    ans.push_back(n);
                else
                    ans.push_back(s.top().second);
            }
            s.push({v[i],i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int>n1 = NSL(heights);
        vector<int>n2 = NSR(heights);
        // for(auto i:n1)
        //     cout<<i<<" ";
        // cout<<"\n";
        // for(auto i:n2)
        //     cout<<i<<" ";
        vector<int>width(n, 0);
        for(int i=0; i<n; i++)
            width[i] = (n2[i]-n1[i]-1);
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, heights[i]*width[i]);
        }
        return ans;
    }
};