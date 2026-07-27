class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x>=0 && x<10) return true;

        int temp = x;
        int digit = 0;
        while(temp != 0){
            digit++;
            temp/=10;
        }

        int check = 0;
        
        for(int i=0;i<(digit/2);i++){
            check = check*10 + (x%10);
            x/=10;
        }

        if(digit % 2 != 0) x/=10;

        if(x == check) return true;
        else return false;
        
    }
};