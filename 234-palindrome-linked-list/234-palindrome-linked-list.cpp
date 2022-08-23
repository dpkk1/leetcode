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
    
    void reverseList(ListNode* &head){
        if(!head || !head->next)
            return;
        Node *prev = NULL, *nextn, *curr=head;
        while(curr != NULL){
            nextn = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextn;
            
        }
        head = prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        if(head->next->next == NULL){
            return (head->val == head->next->val);
        }
        
        
        Node *slow=head, *fast=head, *middle;
        while(fast->next && fast->next->next){
            slow = slow ->next;
            fast = fast -> next -> next;
        }   

        middle = slow->next;

        slow->next = NULL;
        reverseList(middle);
        while(middle && head){
            if(head->val != middle->val)
                return false;
            head = head->next;
            middle = middle->next;
        }
        return true;
    }
};