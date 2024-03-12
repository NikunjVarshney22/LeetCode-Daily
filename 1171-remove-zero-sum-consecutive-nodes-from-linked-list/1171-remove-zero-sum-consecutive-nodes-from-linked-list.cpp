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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int pre = 0;
        ListNode* h = new ListNode(0);
        h->next = head;
        unordered_map<int, ListNode*> seen;
        for(auto i = h; i; i = i->next){
            seen[pre += i->val] = i;
        }
        pre = 0;
        for(auto i = h; i; i = i->next){
            // get rid of the sequence in between, including the end, not the start (current i)
            i->next = seen[pre += i->val]->next;
        }
        return h->next;
    }
};