class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = 0;
        int t_l = t.length(), s_l = s.length();
        int i = 0, j = 0;
        while(j<t_l && i < s_l){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }

        if(j == t_l)
            return 0;
        
        return t_l-j;
        
    }
};