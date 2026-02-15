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
    bool hasCycle(ListNode *head) {
        ListNode* hare = head;
        while(hare != nullptr && hare -> next != nullptr){
            hare = hare -> next ->next;
            head = head -> next;
            if(hare == head) return true;
        }
        return false;
    }
};
