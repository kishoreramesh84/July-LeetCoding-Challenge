 
 /* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=0;
        for(int i=0;i<digits.size();i++)
        {
            if(i==0)
            {
                digits[i]++;
                carry=digits[i]/10;
                digits[i] %= 10;
            }
            else
            {
                digits[i] += carry;
                carry=digits[i]/10;
                digits[i] %= 10;
            }
        }
        if(carry > 0) digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};