class Solution {
public:
    int revNum(int x){
        long long int num =0;

        while(x != 0){
            num = num*10 + (x%10);
            x/=10;
        }

        if(num>INT_MAX || num<INT_MIN) return 0;

        return (int)num;
    }
    int reverse(int x) {
        int res;
        res = revNum(x);
        return res;
    }
};