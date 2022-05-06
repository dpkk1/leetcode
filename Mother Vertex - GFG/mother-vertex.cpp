// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    void DFS(int x, vector<int>&vis, vector<int>adj[]){
        vis[x] = 1;
        for(auto i:adj[x])
            if(!vis[i])
                DFS(i, vis, adj);
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int v, vector<int>adj[]){
	   
	    int motherVertex = 0;
	    vector<int>vis(v,0);
	    for(int i=0; i<v; i++){
	        if(!vis[i]){
    	        DFS(i, vis, adj);
	            motherVertex = i;
	        }
	    }
	    vector<int>bis(v,0);
	    DFS(motherVertex, bis, adj);
	    for(auto i:bis)
	        if(i==0)
	            return -1;
	   return motherVertex;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends