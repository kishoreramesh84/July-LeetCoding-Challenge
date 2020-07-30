

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3406/
*/

class Solution {
public:
    unordered_map<string,vector<string>>dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s)!=dp.end())
            return dp[s];
        vector<string>ans;
        for(auto w:wordDict)
        {
            if(s.substr(0,w.size())==w)
            {
                if(s.size()==w.size())
                    ans.push_back(w);
                else
                {
                    vector<string>tp=wordBreak(s.substr(w.size()),wordDict);
                    for(auto t:tp)
                    {
                        ans.push_back(w+" "+t);
                    }
                }
            }
        }
        dp[s]=ans;
        return ans;
    }
};