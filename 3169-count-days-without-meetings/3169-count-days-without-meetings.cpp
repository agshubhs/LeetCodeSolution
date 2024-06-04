class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        int n = meetings.size();
        int ans = meetings[0][0]-1;
        int currMax = meetings[0][1];
        for(int i = 1 ; i< n;i++){
           if(currMax < meetings[i][0]){
            cout<<i<<" ";
                ans  = ans + meetings[i][0]- currMax-1;
           }
           currMax = max(currMax, meetings[i][1]);
        }
        ans = ans + days-currMax;
        // int ans = 0;
        // int temp = count[0];
        // for(int i = 1;i < days;i++){
        //     if (temp == 0)
        //         ans++;
        //     temp = temp + count[i];
        // }
        // if(temp == 0)
        //     ans++;
        return ans;
        
    }
};