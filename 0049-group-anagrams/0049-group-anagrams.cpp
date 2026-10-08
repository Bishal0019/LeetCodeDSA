class Solution {
public:
    bool isAnagrams(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        string temp2 = s2;
        sort(temp2.begin(), temp2.end());

        if(s1 != temp2) return false;

        return true; 
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        for(int i = 0; i<strs.size(); i++){
            vector<string> temp;
            int count = 0;
            string s = strs[i];
            sort(s.begin(), s.end());
            for(int j=i; j<strs.size(); j++){
                if(isAnagrams(s, strs[j])){
                    temp.push_back(strs[j]);
                    if(j != count) swap(strs[j], strs[i + count]);
                    count++;
                }
            }
            res.push_back(temp);
            i+=count-1;
        }

        return res;
    }
};