

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3390/
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a1,a2;
        a1=5.5*minutes;
        a2=30*hour;
        double ans=abs(a1-a2);
        if(ans > 180.0) ans = 360 - ans;
        return ans;
    }
};

/* Time Complexity: O(1) */