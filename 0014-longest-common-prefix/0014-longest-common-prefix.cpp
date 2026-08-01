class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = "";

        string init = strs[0];
        int i =0;
        while(init[i] != '\0'){
            int flag = 1;
            for(int j=1;j<strs.size();j++){
                if(init[i] != strs[j][i]) flag = 0;
            }
            if(flag){
                pre+=init[i];
                i++;
            }else{
                break;
            }
        }

        return pre;
    }
};