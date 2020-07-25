

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3401/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        if(nums[l]<nums[r]) return nums[l];
        while(l+1<r)
        {
            mid=l+(r-l)/2;
            if(nums[mid]<nums[r]) r=mid;
            else if(nums[mid]>nums[r]) l=mid;
            else r--;
        }
        return nums[l]<nums[r]?nums[l]:nums[r];
    }
};