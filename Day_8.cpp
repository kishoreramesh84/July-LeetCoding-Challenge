

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int i,j,n,k;
        n=nums.size();
        if(n<3) return ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
        {
            if(i>0 and nums[i-1]==nums[i]) continue;
            j=i+1,k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k] < 0) j++;
                else if(nums[i]+nums[j]+nums[k]>0)k--;
                else
                {
                    vector<int>tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    j++;
                    while(j<n and nums[j]==nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};