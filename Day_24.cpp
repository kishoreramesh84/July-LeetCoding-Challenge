

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3400/
*/

class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&adj,int x,int d,vector<int>&vis,vector<int>&tmp)
    {
        if(x==d)
        {
            ans.push_back(tmp);
            return;
        }
        vis[x]=1;
        for(auto a:adj[x])
        {
            if(vis[a]==0)
            {
                tmp.push_back(a);
                dfs(adj,a,d,vis,tmp);
                tmp.pop_back();
            }
        }
        vis[x]=0;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()>0)
            {
               for(auto a:graph[i]) adj[i].push_back(a);
            }
        }
        vector<int>vis(n,0);
        vector<int>tmp;
        tmp.push_back(0);
        dfs(adj,0,n-1,vis,tmp);
        return ans;
    }
};