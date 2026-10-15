class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<int> temp = {start, end};

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= start && intervals[i][0] <= end){
                if(intervals[i][1] > end){
                    end = intervals[i][1];
                    temp[1] = end;
                }
            } else {
                res.push_back(temp);
                start = intervals[i][0];
                temp[0] = start;
                end = intervals[i][1];
                temp[1] = end;
            }
        }
        res.push_back(temp);

        return res;
    }
};