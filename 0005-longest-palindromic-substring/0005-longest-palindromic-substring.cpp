class Solution {
public:
    int max = 0;
    int ini = 0;
    void expand(string &s, int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        left++;
        right--;
        if((right-left+1)>max){
            max = right-left+1;
            ini = left;
        }
    }

    string longestPalindrome(string s) {
        if(s.size()<=1) return s;

        for(int i=0;i<s.size();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }

        return s.substr(ini,max);
    }
};