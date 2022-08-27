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
    int getDecimalValue(ListNode* head) {
        vector<int>v;
        ListNode *temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int base=1, ans=0;
        for(int i=v.size()-1; i>=0; i--){
            if(v[i]==1){
                ans += base;
            }
            base *= 2;
        }
        return ans;
    }
};