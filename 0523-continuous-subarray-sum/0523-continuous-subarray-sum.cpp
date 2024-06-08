class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        if(k == 0)
            return true;
        if(n<2)
            return false;
        
        map<int, int> rem;
        rem[0] = -1;
        for(int i = 0 ;i<n;i++){
            sum  += nums[i];
            sum  %= k;
            if(rem.find(sum) != rem.end()){
                if(rem[sum] +1 < i)
                    return true;

            }
            else{
                rem[sum] = i;
            }        
    }
    return false;
    }
};