class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i=0;i<nums.size()-1;i++){
            int left = i+1;
            int right = nums.size() - 1;
            //closestSum = nums[i] + nums[left] + nums[right];

            while(left<right){
                if(left == i) left++;

                int sum = nums[left] + nums[right] + nums[i];

                if(sum>target) right--;
                else left++;

                if(abs(target-sum) < abs(target - closestSum)){
                    closestSum = sum;
                }
            }
        }

        return closestSum;
    }
};