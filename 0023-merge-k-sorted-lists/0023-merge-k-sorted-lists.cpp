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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;

        ListNode *head = lists[0];
        ListNode *res = head;

        for(int i=1; i<lists.size(); i++){
            if(lists[i] == nullptr) continue;
            else if(head == nullptr && lists[i] != nullptr){
                head = lists[i];
                continue;
            } 
            res = head;
            ListNode *lastaddr = nullptr;
            while(res != nullptr && lists[i] != nullptr){
                if(res->val>lists[i]->val){
                    int temp = res->val;
                    res->val = lists[i]->val;
                    ListNode *addr = res->next;
                    res->next = new ListNode(temp);
                    res->next->next = addr;
                    res = res->next;
                    lists[i] = lists[i]->next;
                }else{
                    if(res->next == nullptr) lastaddr = res;
                    res = res->next;
                }
            }

            ListNode *indexer = (lastaddr == nullptr)?res:lastaddr;
            while(lists[i] != nullptr){
                lastaddr->next = new ListNode(lists[i]->val);
                lastaddr = lastaddr->next;
                lists[i] = lists[i]->next;
            }
        }

        return head;
    }
};