

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,vector<int>>mp;
        while(!q.empty())
        {
            pair<TreeNode*,int>p=q.front();
            q.pop();
            mp[p.second].push_back(p.first->val);
            if(p.first->left)
                q.push({p.first->left,p.second+1});
            if(p.first->right)
                q.push({p.first->right,p.second+1});
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if((it->first)%2==0)
            {
                vector<int>send(it->second.begin(),it->second.end());
                ans.push_back(send);
            }
            else
            {
                vector<int>send(it->second.rbegin(),it->second.rend());
                ans.push_back(send);
            }
        }
        return ans;
    }
};