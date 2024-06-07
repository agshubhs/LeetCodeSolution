class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<int> adj[numCourses];
        vector<int> ans;
        int p_length = prerequisites.size();
        for(int i = 0 ;i<p_length;i++){
            inDegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> q;
        for(int i = 0 ; i< numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto t = q.front();
            ans.push_back(t);
            q.pop();
            for( auto x: adj[t] ){
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
        }
        return ans.size() == numCourses;
    }
};