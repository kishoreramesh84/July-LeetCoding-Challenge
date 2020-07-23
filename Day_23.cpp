

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3399/
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n1=0,n2=0,t=0,r;
        for(auto a:nums) t ^= a;
        r=t & ~(t-1);
        for(auto a:nums)
        {
            if(a&r) n1 ^= a;
            else n2 ^= a;
        }
        return {n1,n2};
    }
};