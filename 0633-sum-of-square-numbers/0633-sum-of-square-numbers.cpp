class Solution {
public:
    bool judgeSquareSum(int c) {
        // bool ans = false;
        if(c ==0)
            return true;
        for(long i = 0;i *i <c;i++){
            int temp = sqrt(c - i*i);
            if(temp*temp == (c- i*i))
                return true;
        }

        return false;
        
    }
};