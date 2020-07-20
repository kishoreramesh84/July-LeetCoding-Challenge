

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *ans=NULL,*prev;
        while(head)
        {
            if(head->val!=val)
            {
                if(ans==NULL)
                {
                    ans=head;
                    prev=head;
                }
                else
                {
                    prev->next=head;
                    prev=prev->next;
                }
            }
            head=head->next;
        }
        if(ans)prev->next=NULL;
        return ans;
    }
};