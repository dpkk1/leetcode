// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        pair<int,int>src,des;
        for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){
               if(grid[i][j] == 1)
                    src=make_pair(i,j);
               else if(grid[i][j] == 2)
                    des=make_pair(i,j);
           } 
        }
        queue<pair<int,int>>q;
        q.push(src);
        grid[src.first][src.second] = -1;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            if(x-1>=0 && (grid[x-1][y]==3 || grid[x-1][y]==2)){
                if(grid[x-1][y]==2)
                    return true;
                else{
                    q.push({x-1,y});
                    grid[x-1][y]=-1;
                }
            }
            if(x+1<m && (grid[x+1][y]==3 || grid[x+1][y]==2)){
                if(grid[x+1][y]==2)
                    return true;
                else{
                    q.push({x+1,y});
                    grid[x+1][y]=-1;
                }
            }
            if(y-1>=0 && (grid[x][y-1]==3 || grid[x][y-1]==2)){
                if(grid[x][y-1]==2)
                    return true;
                else{
                    q.push({x,y-1});
                    grid[x][y-1]=-1;
                }
            }
            if(y+1<n && (grid[x][y+1]==3 || grid[x][y+1]==2)){
                if(grid[x][y+1]==2)
                    return true;
                else{
                    q.push({x,y+1});
                    grid[x][y+1]=-1;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends