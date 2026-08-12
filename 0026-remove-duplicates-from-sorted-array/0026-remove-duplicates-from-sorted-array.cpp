class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int distinct = 0;

        for(int i=0;i<nums.size()-1;i++){
            int j = i+1;
            while(j<nums.size()){
                if(nums[i] == nums[j]){
                    nums.erase(nums.begin() + j);
                } 
                else {
                    j++;
                }
            }
        }

        return nums.size();
    }
};