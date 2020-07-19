

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3394/
*/


class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pq) {
        vector<int>in(n,0);
        vector<int>an1,an2;
        vector<vector<int>>adj(n);
        for(auto &a:pq)
        {
            adj[a[1]].push_back(a[0]);
            in[a[0]]++;
        }
        int ct=0;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            an1.push_back(x);
            q.pop();
            ct++;
            for(auto a:adj[x])
            {
                in[a]--;
                if(in[a]==0) q.push(a);
                    
            }
        }
        if(ct!=n) return an2;
        return an1;
    }
};