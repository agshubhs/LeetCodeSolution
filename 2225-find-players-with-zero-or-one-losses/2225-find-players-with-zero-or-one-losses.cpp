class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        for(int i = 0; i<n; i++){
            inDegree[matches[i][1]]++;
            outDegree[matches[i][0]]++;
        }
        vector<int> lost_0;
        vector<int> lost_1;
        for(auto &it:outDegree){
            if(inDegree.find(it.first) == inDegree.end()){
                lost_0.push_back(it.first);
            }
        }

        for(auto &it:inDegree){
            if(it.second == 1){
                lost_1.push_back(it.first);
            }
        }
        sort(lost_0.begin(), lost_0.end());
        sort(lost_1.begin(), lost_1.end());
        return {lost_0,lost_1};
        
    }
};