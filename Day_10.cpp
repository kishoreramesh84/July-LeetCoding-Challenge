

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
Node *create(int d)
{
    Node *ne=new Node;
    ne->val=d;
    ne->prev=NULL;
    ne->next=NULL;
    ne->child=NULL;
    return ne;
}
class Solution {
public:
    Node *ans,*prev;
    void find(Node *root)
    {
        if(root==NULL) return;
        if(ans==NULL)
        {
            ans=create(root->val);
            prev=ans;
        }
        else
        {
            Node *n=create(root->val);
            Node *tmp=prev;
            prev->next=n;
            n->prev=prev;
            prev=prev->next;
            
        }
        find(root->child);
        find(root->next);
    }
    Node* flatten(Node* head) {
        ans=NULL;
        if(head==NULL) return ans;
        find(head);
        return ans;
    }
};