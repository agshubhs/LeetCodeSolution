class Solution {
public:
    int M;
    int N;
    bool dfs(int i , int j , vector<vector<char>> & board, string& word, int idx){
            
            if(idx == word.length())
                return true;

            if(i<0 || j<0 || i>= M || j>=N || board[i][j] == '#')
                return false;

            if( board[i][j] != word[idx])
                return false;

            char ch = board[i][j];
            board[i][j] = '#';
             bool found = dfs(i + 1, j,board, word, idx + 1)
                || dfs(i - 1, j,board, word, idx + 1 )
                || dfs(i, j+1,board, word, idx + 1)
                || dfs(i, j-1,board, word, idx + 1);
           
            board[i][j] = ch;
            return found;

            
                    
        }
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        N = board[0].size();        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dfs(i,j,board,word, 0))
                    return true; 
            }
        }
        return false;
    
    }
};