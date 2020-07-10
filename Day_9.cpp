

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0,S,E;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            S=q.front().second;
            E=q.back().second;
            ans=max(ans,E-S+1);
            int sz=q.size();
            while(sz--)
            {
                pair<TreeNode*,int>p=q.front();
                q.pop();
                int id=p.second-S;
                if(p.first->left) q.push({p.first->left,2*id+1});
                if(p.first->right) q.push({p.first->right,2*id+2});
            }
        }
        return ans;
    }
};