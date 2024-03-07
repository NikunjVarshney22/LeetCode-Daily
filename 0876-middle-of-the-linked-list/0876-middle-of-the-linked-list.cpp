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
    int listLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int len = listLength(head);
        int middle = len / 2;
        ListNode* temp = head;
        int count = 0;
        while (count < middle) {
            temp = temp->next;
            count++;
        }
        return temp;
    }
};