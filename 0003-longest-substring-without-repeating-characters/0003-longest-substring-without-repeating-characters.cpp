class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index =0;
        int max = 0;
        string substr;
        int size = 0;
        for(int i=0;i<s.size();i++){
            if(substr.find(s[i]) != string :: npos){
                while(substr[index] != s[i]){
                    index++;
                }index++;

                substr = substr.substr(index);
                if(size>max) max = size;
                substr+=s[i];
                size = substr.size();
                index = 0;

            }else{
                substr+=s[i];
                size++;
            }
        }

        if(max>size) return max;
        else return size;
    }
};