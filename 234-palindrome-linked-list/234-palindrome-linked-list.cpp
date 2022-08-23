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
    bool isPalinString(string s){
        int n = s.length();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        Node *temp = head;
        string s="";
        char c;
        while(temp != NULL){
            c = temp->val;
            s.push_back(c);
            temp = temp->next;
        }
        return isPalinString(s);
    }
};