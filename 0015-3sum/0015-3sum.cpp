class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int triplet[3];

        if (nums.size() == 3) {
            if ((nums[0] + nums[1] + nums[2]) == 0) {
                res.push_back({nums[0], nums[1], nums[2]});
                return res;
            }
        }

        sort(nums.begin(), nums.end());
        int left;
        int right;

        for (int i = 0; i < nums.size() - 1; i++) {
            left = i + 1;
            right = nums.size() - 1;

            if(i>0 && i<nums.size()-1 && nums[i] == nums[i-1]){
                continue;
            }

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(nums[left] == nums[left-1] && left<right) left++;
                    while(nums[right] == nums[right+1] && right>left) right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};