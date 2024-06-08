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

    long dfs(int i, int j,int move,vector<vector<vector<long>>> & memo){
    if(move<0)
        return 0;
    if(i < 0 || i>=M || j< 0 ||j >=N )
            return 1;
    
    if(memo[i][j][move] != -1)
        return memo[i][j][move];
    long total = 0;
    long a = dfs(i+1,j,move-1, memo);
    long b = dfs(i-1,j,move-1,memo);
    long c = dfs(i,j+1,move-1,memo);
    long d = dfs(i,j-1,move-1,memo);
    total = (a+b+c+d)%MOD;
    memo[i][j][move] = total % MOD;
    return total;
   }
    
};