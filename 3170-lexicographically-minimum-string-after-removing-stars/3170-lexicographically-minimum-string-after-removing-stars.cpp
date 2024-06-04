class Solution {
public:
    
    string clearStars(string s) {
        auto comp =[](const pair<int, int>& p1,const pair<int, int>& p2){
        if(p1.first == p2.first)
           return p2.second > p1.second;
           return p1.first > p2.first;
       };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(comp)> pq;
        int n = s.size();
        vector<int> vis(n,0);
        for(int i = 0;i<n;i++){
            if(s[i] =='*'){
                vis[pq.top().second]= 1;
                pq.pop();
                vis[i] = 1;
            }
            else{
                pq.push({s[i],i});
            }
        }
        
      
          string ans = "";
        for(int i = 0; i<n;i++){
            if(vis[i] == 0)
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};