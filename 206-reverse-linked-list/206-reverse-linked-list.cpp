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

#define Node ListNode

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        Node *curr=head, *prev=NULL, *nextn;
        while(curr!=NULL){
            nextn = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = nextn;
        }
        return prev;
    }
};