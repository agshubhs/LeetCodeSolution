class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> rem;
        int currSum = 0;
        rem[0] = 1;
        for(int num : nums){
            currSum += num;
            int mod = currSum%k;
            if(mod<0){
                mod +=k;
            }
            if(rem.find(mod)!= rem.end()){
                count += rem[mod];
                rem[mod] +=1; 
            }
            else
            rem[mod] = 1;
        }
        return count;
    }
};