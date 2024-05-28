class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxLength = 0;
        int length = 0;
        int sum = 0;
        int j =0;
        for(int i = 0;i<n;i++){
            length++;
            sum += abs(s[i]-t[i]);
            
            if(sum<=maxCost){
                
                maxLength = max(length, maxLength);
            }
            else {
                sum = sum - abs(s[j]-t[j]);
                j++;
                length--; 
            }
        }

        return maxLength;

    }
};