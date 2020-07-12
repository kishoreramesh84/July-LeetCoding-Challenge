

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3388/
*/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++)
        {
            res |= ((n>>i)&1)<<(31-i);
        }
        return res;
    }
};