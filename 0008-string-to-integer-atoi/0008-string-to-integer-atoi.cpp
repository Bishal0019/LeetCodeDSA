class Solution {
public:
    int myAtoi(string s) {
        long long int res = 0;
        int sign = 1;
        int started = 0;
        for(int i=0;i<s.size();i++){
            if(i==0){
                if(s[i] == '-'){
                    sign = 0;
                    started = 1;
                }
                else if(s[i] == '+'){
                    started = 1;
                }
                else if(isdigit(s[i])){
                    res = res*10 + (s[i] - '0');
                    started = 1;
                }
                else if(s[i] == ' '){
                    continue;
                }
                else{
                    break;
                }
            } else {
                if(isdigit(s[i])){
                    res = res*10 + (s[i] - '0');
                    if(res>pow(2,31)) break;
                    started = 1;
                } 
                else if(started == 0 && s[i] == ' ') continue;
                else if(started == 0 && s[i] == '-'){
                    started = 1;
                    sign = 0;
                }
                else if(started == 0 && s[i] == '+'){
                    started = 1;
                    continue;
                }
                else {
                    break;
                }
            }

        }

        if(!sign){
            res = -(res);
            if(res<=(-(pow(2,31)))) res = -(pow(2,31));
        }
        else{
            if(res>=(pow(2,31)-1)) res = pow(2,31) -1;
        }
        return res;
    }
};