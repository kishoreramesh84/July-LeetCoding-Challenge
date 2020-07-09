
/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int,vector<int>>mp;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<TreeNode*,int>p=q.front();
            mp[p.second].push_back(p.first->val);
            q.pop();
            if(p.first->left)
                q.push({p.first->left,p.second+1});
            if(p.first->right)
                q.push({p.first->right,p.second+1});
        }
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};