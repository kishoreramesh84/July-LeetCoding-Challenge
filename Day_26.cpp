

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3402/
*/

class Solution {
public:
    int addDigits(int num) {
        while(num > 9)
        {
            int add=0;
            while(num)
            {
                add += num%10;
                num /= 10;
            }
            num=add;
        }
        return num;
    }
};