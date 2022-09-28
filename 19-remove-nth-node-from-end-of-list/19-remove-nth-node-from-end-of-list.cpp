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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        Node *start= new Node(0);
        start -> next = head;
        Node *slow = start;
        Node *fast = start;
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        while(fast -> next != NULL){
            fast = fast ->next;
            slow = slow -> next;
        }
        slow -> next = slow-> next->next;
        return start->next;
    }
};