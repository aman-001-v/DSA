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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head;
        while(n-- != 0) f = f -> next;
        ListNode* dummy = new ListNode(0 , head);
        head = dummy;
        while(f != nullptr){
            head = head -> next;
            f = f -> next;
        }
        head -> next = head -> next -> next;
        return dummy -> next;
    }
};
