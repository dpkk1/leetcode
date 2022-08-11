class Solution {
public:
    bool search(vector<vector<char>>& board, int i, int j, string& word, int ind, vector<vector<bool>>&vis){
        if(ind==word.length()-1)
            return true;
        vis[i][j] = true;
        if(i>0 && !vis[i-1][j] && board[i-1][j]==word[ind+1] && search(board, i-1, j, word, ind+1, vis))
            return true;
        
        if(j>0 && !vis[i][j-1] && board[i][j-1]==word[ind+1] && search(board, i, j-1, word, ind+1, vis))
            return true;
        
        if(i<board.size()-1 && !vis[i+1][j] && board[i+1][j]==word[ind+1] && search(board, i+1, j, word, ind+1, vis))
            return true;
        
        if(j<board[0].size()-1 && !vis[i][j+1] && board[i][j+1]==word[ind+1] && search(board, i, j+1, word, ind+1, vis))
            return true;
        vis[i][j] = false;
        
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == word[0] && search(board, i, j, word, 0, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};