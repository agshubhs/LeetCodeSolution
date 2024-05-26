class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return nums[0];
        if(size == 2)
            return max(nums[0], nums[1]);
        int last = max(nums[1],nums[0]);
        int secondLast = nums[0];
        int temp;
        for(int i = 2;i<size;i++){
            temp  = last;
            if(last < (secondLast + nums[i])){
                last = secondLast + nums[i];
                secondLast = temp;
            }
            else{
                // last = secondLast;
                secondLast = last;
            }
        } 

        return max(last, secondLast);
         


        
    }
};