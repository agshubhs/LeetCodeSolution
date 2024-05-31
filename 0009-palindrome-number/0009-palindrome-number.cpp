class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x< 0)
            return false;

        long reverse = 0 ;
        long org = x;
        int r;
        while(x !=0){
                r = x%10;
                reverse = reverse *10 + r;
                x = x/10;
        }

        return (org==reverse);
    
    }
};