class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int c0=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j]==0)
                    c0++;
        if(c0 == n*m)
            return 0;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(mat[i][j] == 2)
                    q.push({i,j});
        }
        int t = -1;
        while(!q.empty()){
            int c = q.size();
            for(int i=0; i<c; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x-1>=0 && mat[x-1][y]==1){
                    mat[x-1][y]=2;
                    q.push({x-1, y});
                }
                if(x+1<n && mat[x+1][y]==1){
                    mat[x+1][y]=2;
                    q.push({x+1, y});
                }
                if(y-1>=0 && mat[x][y-1]==1){
                    mat[x][y-1]=2;
                    q.push({x, y-1});
                }
                if(y+1<m && mat[x][y+1]==1){
                    mat[x][y+1]=2;
                    q.push({x, y+1});
                }  
            }
            t += 1;
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(mat[i][j]==1){
                    t = -1;
                    break;
                }              
        }
        return t;
    }
};