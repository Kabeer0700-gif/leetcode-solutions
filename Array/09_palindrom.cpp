class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int dup = x;
        long rev = 0;
        while(x != 0){
            
            int lastDigit = x%10;
            rev = rev*10 + lastDigit;
            x = x/10;
        }

        if(dup == rev) return true;
        else return false;
    }
};
