class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> sorted;

        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sorted.push_back(temp);
        }

        for(int i = 0; i<strs.size(); i++){

            vector<string> temp;
            int count = 0;

            for(int j=i; j<strs.size(); j++){
                if(sorted[i] == sorted[j]){
                    temp.push_back(strs[j]);

                    if(j != i+count){
                        swap(strs[j], strs[i+count]);
                        swap(sorted[j], sorted[i+count]);
                    }

                    count++;
                }
            }

            res.push_back(temp);
            i+=count-1;
        }

        return res;
    }
};