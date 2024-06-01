class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n,0);
        int edgeLength = edges.size();
        for(int i = 0; i<edgeLength;i++){
            inDegree[edges[i][1]]++;
        }
        int flag = 0;
        int ans = 0;
        for (int i = 0; i< n;i++){
            if(inDegree[i] == 0 && flag == 0){
                flag =1;
                ans = i;
            }
            else if( inDegree[i]== 0 && flag ==1){
                return -1;
            }
        }
        return ans;
    }
};