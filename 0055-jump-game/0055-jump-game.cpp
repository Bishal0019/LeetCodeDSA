class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int max = nums[0];
        while(i < nums.size()){
            if(i <= max && i+nums[i] > max) max = i+nums[i];
            i++;

            if(max >= nums.size() - 1) return true;
        }

        return false;
    }
};