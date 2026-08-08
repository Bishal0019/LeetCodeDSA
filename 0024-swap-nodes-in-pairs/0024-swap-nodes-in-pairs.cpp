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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode *first = head->next;
        ListNode *second = head;
        ListNode *prev = nullptr;

        int i=0;
        while(first != nullptr && second != nullptr){
            second->next = first->next;
            first->next = second;
            if(i==0) head = first;

            if(prev != nullptr) prev->next = first;
            prev = second;
            second = second->next;
            if(second == nullptr) return head;
            first = second->next;
            i++;
        }

        return head;
    }
};