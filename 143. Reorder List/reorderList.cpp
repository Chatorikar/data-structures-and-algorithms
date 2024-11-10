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
    void reorderList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast = head;

        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        } 

        ListNode* prev = NULL;
        ListNode* cur = slow->next;
        slow->next = NULL;
        ListNode* temp = slow;

        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next=temp1;

            first = temp1;
            second = temp2;            
        }
        
    }
};