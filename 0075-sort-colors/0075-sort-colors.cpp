class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid = start;
        int temp;
        while(mid<=end){
            if(nums[mid]==0){
                temp= nums[mid];
                nums[mid]= nums[start];
                nums[start] = temp;   
            start++;
            mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                temp= nums[mid];
                nums[mid]= nums[end];
                nums[end] = temp;
                end--;
            }
        }
    }
};