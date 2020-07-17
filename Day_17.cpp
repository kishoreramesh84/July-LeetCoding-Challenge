

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
*/



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto a:nums) mp[a]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(pq.size()<k) pq.push({it->second,it->first});
            else
            {
                auto p=pq.top();
                if(p.first<=(it->second))
                {
                    pq.pop();
                    pq.push({it->second,it->first});
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};