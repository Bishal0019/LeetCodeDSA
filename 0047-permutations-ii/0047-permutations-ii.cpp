class Solution {
public:
    vector<vector<int>> res;
    
    void permutations(vector<int>& nums, int pos){
        if(pos == nums.size()-1){
            auto it = find(res.begin(), res.end(), nums);

            if(it == res.end()) res.push_back(nums);
            return;
        }

        for(int i=pos; i<nums.size(); i++){
            swap(nums[pos], nums[i]);
            permutations(nums, pos+1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutations(nums, 0);
        return res;
    }
};