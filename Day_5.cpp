

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3381/
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        return __builtin_popcount(x);
    }
};