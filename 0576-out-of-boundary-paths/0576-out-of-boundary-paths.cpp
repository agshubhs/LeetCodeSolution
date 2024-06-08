class Solution {
public:
    int M;
    int N;
    
    const int MOD = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long>>> memo = vector<vector<vector<long>>>(m + 1, vector<vector<long>>(n + 1, vector<long>(maxMove + 1, -1)));
        M = m;
        N = n;
        int ans =  dfs(startRow,startColumn,maxMove,memo);        
        return ans;
    }

    int dfs(int i, int j,int move,vector<vector<vector<long>>> & memo){
    if(move<0 )
        return 0;
    if(i < 0 || i>=M || j< 0 ||j >=N )
            return 1;
    
    if(move <= i && move <= j && move + i < M && move + j < N) return 0;

    if(memo[i][j][move] != -1)
        return memo[i][j][move];
    

    int total = 0;
    total  = (total+ dfs(i+1,j,move-1, memo))%MOD;
    total = (total+ dfs(i-1,j,move-1,memo))%MOD;
    total = (total+ dfs(i,j+1,move-1,memo))%MOD;
    total = (total+ dfs(i,j-1,move-1,memo))%MOD;
    memo[i][j][move] = total;
    return total;
   }
    
};