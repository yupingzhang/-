Linked List Cycle II 

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?


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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) 
            return NULL;
        ListNode *p1 = head, *p2 = head;
        while(p1 != NULL && p2 != NULL) {
            p1 = p1->next;
            if(p2->next != NULL) {
                p2 = p2->next->next; }
            else{
                p2 = p2->next; }
            if(p1 == p2) {
                break;
            }
        }
        if(p2 == NULL) return NULL;   //check until end, no cycle
        // move on X steps then get to the start point of the cycle 
        //(how to deduce):  t = X + nY + K  ,  2t = X + mY+ K
        // 2X + 2nY + 2K = X + mY + K
		// =>   X+K  =  (m-2n)Y
		// => X+X+K  =  (m-2n)Y + X   --> at the cycle start
        p1 = head;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};