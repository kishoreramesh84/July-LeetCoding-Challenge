

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3392/
*/

class Solution {
public:
    double find(double b,long long e)
    {
        double res=1.0;
        while(e)
        {
            if(e&1)
                res *= b;
            b *= b;
            e = e >> 1;
        }
        return res;
    }
    double myPow(double x, int n) {
        double ans=find(x,abs(n));
        if(n<0) ans = 1.0/ans;
        return ans;
    }
};