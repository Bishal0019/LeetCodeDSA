class Solution {
public:
    bool isValid(string s) {
        stack<char> res;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}') res.push(s[i]);

            else if(s[i] == '(' && res.size()>0){
                char ch = res.top();
                res.pop();

                if(ch != ')') return false;
            } else if(s[i] == '{' && res.size()>0){
                char ch = res.top();
                res.pop();

                if(ch != '}') return false;
            } else if(s[i] == '[' && res.size()>0){
                char ch = res.top();
                res.pop();

                if(ch != ']') return false;
            } else{
                return false;
            }
        }

        if(res.size() == 0) return true;
        else return false;
    }
};