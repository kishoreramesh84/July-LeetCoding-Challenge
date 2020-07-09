
''' Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
'''


class Solution:
    def arrangeCoins(self, n: int) -> int:
        ans=0
        l=1
        r=1e9
        while l<=r :
            mid=l+(r-l)//2;
            if (mid*(mid+1))//2 <= n:
                ans=mid
                l=mid+1
            else:
                r=mid-1
        return int(ans)
        
#Time Complexity: O(log 1e9)