// Remove Duplicates from Sorted List II 
// 
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// 
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
// 
// Analysis:
// One pointer is needed to store the previous element.
// Other pointer point to current element and compare to the next one.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) { return head; }
        ListNode *pre = new ListNode(0);
        pre->next = head;
        head = pre;
        ListNode *p = head;
        
        while(p->next != NULL) {
            ListNode *curr = p->next;
            while((curr->next != NULL) && (curr->val==curr->next->val) ) {
                curr = curr->next;
            }
            if(curr != p->next) {
                p->next = curr->next;
            }else{
                p = curr;
            }
        }
        return head->next;
    }
};