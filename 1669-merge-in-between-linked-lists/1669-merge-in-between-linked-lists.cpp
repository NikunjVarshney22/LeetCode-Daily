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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        ListNode *temp1 = list1;
        //running a loop to find the previous node from where it will join the list with list2
        while(i<a-1){
            temp1 = temp1->next;
            i++;
        }
        
        ListNode *temp2 = temp1->next;
        temp1->next = list2;
        //this loop is for the next node where we have to join the tail of list2
        while(i<b){
            temp1 = temp2;
            temp2 = temp2->next;
            delete(temp1);//free the nodes to be removed
            i++;
        }
        //iterating through list2 to find the tail and joining it with the list1
        while(list2->next!=NULL){
            list2 = list2->next;
        }
        list2->next = temp2;
        
        return list1;
    }
};