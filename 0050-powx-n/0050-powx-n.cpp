class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;

        bool isNegative = (n<0?true:false);
        long long power = n;
        if(isNegative) power = -(power);

        while(power>0){
            if(power % 2 == 1){
                res *= x;
            }

            x*=x;
            power/=2;
        }

        if(isNegative) res = 1/res;

        return res;
    }
};