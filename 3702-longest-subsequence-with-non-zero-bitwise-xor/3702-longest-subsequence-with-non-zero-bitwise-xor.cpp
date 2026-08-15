class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int curr = 0;
        int res = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                curr++;
                continue;
            }
            res = (res^nums[i]);
            curr++; 
        }

        if(res != 0) return curr;
        if(res == 0){
            for(int i=0;i<nums.size();i++){
                if(nums[i] != 0){
                    curr--;
                    return curr;
                }
            }
        }

        return 0;
    }
};