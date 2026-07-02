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
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* l1 = head;
        ListNode* l2 = prev;

        ListNode* next1 = NULL, *next2 = NULL;
        while(l2){
            next1 = l1->next;
            next2 = l2->next;
            l1->next = l2;
            l2->next = next1;
            l1 = next1;
            l2 = next2;
        }



    }
};
