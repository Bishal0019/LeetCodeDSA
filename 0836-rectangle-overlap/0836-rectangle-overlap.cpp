class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<int> left, right;

        if(rec1[0] < rec2[0]){
            left = rec1;
            right = rec2;
        } else {
            left = rec2;
            right = rec1;
        }

        if(right[0] < left[2]){
            if((right[1] >= left[1] && right[1] <= left[3]) ||
            right[3] <= left[3] && right[3] >= left[1] ||
            right[1] < left[1] && right[3] > left[3]){
                return true;
            }
        }

        return false;
    }
};