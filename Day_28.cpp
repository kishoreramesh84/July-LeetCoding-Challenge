

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3404/
*/

class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int leastInterval(vector<char>& tasks, int n) {
        int max_freq=0,times=0;
        vector<int>hash(26,0);
        for(char t:tasks)
            hash[t-'A']++;
        for(int i=0;i<26;i++)
            max_freq=max(max_freq,hash[i]);
        for(int i=0;i<26;i++)
        {
            if(max_freq==hash[i]) times++;
        }
        int ans=(max_freq-1)*n+max_freq;
        ans += (times-1);
        ans=max(ans,tasks.size());
        return ans;
    }
};