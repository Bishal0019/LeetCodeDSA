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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *cur, *next, *last, *prev = nullptr;
        int iter = 0;

        while(temp != nullptr){
            int i=0;
            cur = temp;
            while(i<k-1 && temp != nullptr){
                temp = temp->next;
                i++;
            }

            if(temp == nullptr) break;
            last = temp;
            if(prev != nullptr){
                prev->next = temp;
            }
            temp = temp->next;

            for(int j = 0; j<k-1; j++){
                if(j==0) prev = cur;
                next = cur->next;
                cur->next = last->next;
                last->next = cur;
                //last = cur;
                cur = next;
            }

            if(iter == 0) head = cur;
            iter++;
        }

        return head;
    }
};