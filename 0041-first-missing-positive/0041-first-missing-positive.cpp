class Solution {
public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0]>1 || nums[0]<=0) return 1;
            else return nums[0]+1;
        }

        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i] <=0 || nums[i] > n){
                i++;
            } else {
                if(nums[i] != i+1){
                    if(nums[nums[i]-1] == nums[i]) i++;
                    else{
                        swap(&nums[i], &nums[nums[i]-1]);
                    }
                } else {
                    i++;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
};