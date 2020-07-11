

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3387/
*/


class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>nums,int i,vector<int>&v)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        find(nums,i+1,v);
        v.pop_back();
        find(nums,i+1,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        find(nums,0,v);
        return ans;
    }
};