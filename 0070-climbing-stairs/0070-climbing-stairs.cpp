class Solution {
public:
    int climbStairs(int n) {
        int last;
        int secondLast;
        if (n==1)
            return 1;
        if (n==2)
            return 2;
         
         last =2;
         secondLast =1;
        int current;
        for(int i = 3; i<=n;i++){
            current = last + secondLast;
            secondLast = last;
            last = current;
        }

        return current;
    }
};