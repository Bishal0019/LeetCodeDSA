class Solution {
public:

    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int ans = 0;
        int max = ans;
        int left = 0;

        for(int right = left;right<s.size();right++){
            auto it = freq.find(s[right]);

            if(it == freq.end()){
                freq[s[right]]++;
                ans++;
            } else {
                freq[s[right]]++;
                ans++;

                while(freq[s[right]]>2){
                    freq[s[left]]--;
                    left++;
                    ans--;
                }
            }

            if(ans>max) max = ans;
        } 

        return max;
    }
};