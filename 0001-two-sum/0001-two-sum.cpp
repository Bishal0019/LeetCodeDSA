class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> indexmap;
        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i];
            if (indexmap.find(diff) != indexmap.end()){
                return {indexmap[diff],i};
            }
            indexmap[nums[i]] = i;
        }
        return {};
    }
};