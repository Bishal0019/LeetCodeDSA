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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *l3 = head;
        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carry;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            sum = l1->val + carry;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            carry = sum/10;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            sum = l2->val + carry;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            carry = sum/10;
            l2 = l2->next;
        }

        while(carry>0){
            l3->next = new ListNode(carry%10);
            l3 = l3->next;
            carry/=10;
        }

        return head->next;
    }
};