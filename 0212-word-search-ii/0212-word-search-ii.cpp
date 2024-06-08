class Solution {
public:
    struct TrieNode{
        bool isWord;
        TrieNode * child[26];
    };
    int M;
    int N;
    void dfs(vector<vector<char>>& board,int i, int j, TrieNode * root, vector<string> & ans, string s){
        if(root->isWord){
            ans.push_back(s);
            root->isWord = false;
        }
        if(i<0 || j<0 || i>=M || j>=N) return;
        if(board[i][j]=='#') return;
        char ch = board[i][j];
        board[i][j]='#';
        if(root->child[ch-'a'] != NULL){
            s.push_back(ch);
            dfs(board,i+1,j,root->child[ch-'a'],ans,s);
            dfs(board,i-1,j,root->child[ch-'a'],ans,s);
            dfs(board,i,j+1,root->child[ch-'a'],ans,s);
            dfs(board,i,j-1,root->child[ch-'a'],ans,s);
            s.pop_back();
        }
        board[i][j]= ch;

    }
     
    TrieNode* root= new TrieNode();
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int wordCount = words.size();
        
        for(int i = 0;i<wordCount;i++){
            TrieNode * curr = root;
            for(int j = 0; j< words[i].size();j++){
                int idx = words[i][j]-'a';
                if(curr->child[idx]== NULL){
                    curr->child[idx] = new TrieNode();
                }
                curr = curr->child[idx];
            }
            curr->isWord = true;
        }
        M = board.size();
        N = board[0].size();
        vector<string> ans;
        for(int i =0;i<M;i++)
            for(int j=0;j<N;j++){
                char ch = board[i][j];
              if(root->child[ch-'a'] != NULL){
                dfs(board,i,j,root,ans,"");
              } 
            }
        
        return ans;

    }
};