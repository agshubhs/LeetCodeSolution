class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = 0;
        int t_l = t.length();
        int s_l = s.length();
        int i = 0;
        int j = 0;
        while(j<t_l && i < s_l){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        
        return t_l-j;
        
    }
};