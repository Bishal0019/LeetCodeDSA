class Solution {
public:
    vector<string> getLastWord(string s){
        vector<string> res;

        string word = "";
        for(char c : s){
            if(c == ' ' || c == '\n' || c == '\t' || c == '\0'){
                if(word.size() > 0){
                    res.push_back(word);
                    word = "";
                } 
            } else {
                word.push_back(c);
            }
        }
        if(word.size() > 0) res.push_back(word);

        return res;
    }

    int lengthOfLastWord(string s) {
        vector<string> word = getLastWord(s);

        // for ( string s : word){
        //     cout<<s<<',';
        // }

        if(word.size() == 0){
            return 0;
        } else {
            if(word[word.size() - 1].size() == 0) return 0;
            else return word[word.size()-1].size();
        }
    }
};