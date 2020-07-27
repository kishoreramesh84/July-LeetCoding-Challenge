

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3403/
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
    unordered_map<int,int>mp;
    int index;
    TreeNode*construct(vector<int>&in,vector<int>&po,int st,int end)
    {
        if(st>end) return NULL;
        TreeNode *ne=new TreeNode(po[index]);
        int mid=mp[po[index]];
        --index;
        if(st==end) return ne;
        ne->right=construct(in,po,mid+1,end);
        ne->left=construct(in,po,st,mid-1);
        return ne;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        index=inorder.size()-1;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return construct(inorder,postorder,0,index);
    }
};