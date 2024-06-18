class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> p;
         int n = difficulty.size();
         for(int i = 0 ;i<n;i++){
            p.push_back({difficulty[i],profit[i]});
         }
         sort(p.begin(),p.end());
         sort(worker.begin(),worker.end());
         int j = 0;
         int maxProfit= 0;
         int best = 0;
         for(int i = 0;i<worker.size();i++){
            while(worker[i] >= p[j].first && j<n){
            best = max(best, p[j++].second);
            }
            
                maxProfit += best;

         }
         return maxProfit;
    }
};