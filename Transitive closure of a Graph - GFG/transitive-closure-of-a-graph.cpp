// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void DFS(int x, vector<int>&vis, vector<int>adj[]){
        vis[x]=1;
        for(auto i:adj[x])
            if(!vis[i])
                DFS(i, vis, adj);
    }

    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> g){
        vector<vector<int>>ans;
        vector<int>adj[n];
        int row = g.size();
        int col = g[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(g[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            vector<int>vis(n,0);
            DFS(i, vis, adj);
            ans.push_back(vis);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}  // } Driver Code Ends