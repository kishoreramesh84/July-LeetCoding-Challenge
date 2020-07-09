

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/
*/

class Solution {
public:
    int nthUglyNumber(int n) {
       int i=0,j=0,k=0;
        vector<int>nums;
        nums.push_back(1);
        if(n==0) return 0;
        while(nums.size()<n)
        {
            int x=nums[i]*2;
            int y=nums[j]*3;
            int z=nums[k]*5;
            int mi=min(x,min(y,z));
            nums.push_back(mi);
            //cout<<mi<<" ";
            if(mi==x) i++;
            if(mi==y) j++;
            if(mi==z) k++;
        }
        return nums[n-1];
    }
};