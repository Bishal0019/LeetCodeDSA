class Solution {
public:
    int jump(vector<int>& nums) {
       int i = nums.size() -1;
       int jumps = 0;

       while(i > 0){
        int max_index = i;
        int step = 0;
        for(int j=i-1; j>=0; j--){
            step++;
            if(nums[j] >= step){
                if(j<max_index){
                    max_index = j;
                }
            }
        }

        i = max_index;
        jumps++;
       }

       return jumps;
    }
};