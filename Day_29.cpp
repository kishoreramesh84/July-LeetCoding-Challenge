

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3405/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){ 
            return 0;
        }
        int A = 0; 
        int B = 0; 
        int C = 0; 
        int prevA = 0;
        int prevB = INT_MIN;
        int prevC = INT_MIN;
        for (int i = 0; i < prices.size(); i++){
            A = max(prevA, prevC); 
            B = max(prevB, prevA - prices[i]); 
            C = prevB + prices[i];
            prevA = A;
            prevB = B;
            prevC = C;
        }
        return max(A, C); 
    }
};