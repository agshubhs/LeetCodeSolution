class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int> count(60,0);
        for(int i = 0;i<n;i++){
            count[s[i]-'A']++;
        }

        int ans = 0;
        int flag = 0;
        for(int i = 0 ;i<60;i++){
            ans += (count[i]/2)*2;
            if(count[i] %2 == 1)
                flag =1;
        }
        return flag==1? ans+1:ans;

        
    }
};