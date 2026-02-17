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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* t = dummy;
        for(int i = 0; i < left - 1; i++){
            t = t -> next;
        }
        // ListNode* t2 = t;
        // for(int i = 0; i< right - left + 2; i++){
        //     t2 = t2 -> next;
        // }
        //cout << t -> val << endl;
        ListNode* prev = nullptr;
        ListNode* curr = t -> next;
        ListNode* next = nullptr;
        for(int i = 0; i< right - left + 1; i++){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        t -> next = prev;
        while(t -> next != nullptr){
            t = t -> next;
        }
        t -> next = next;
        return dummy -> next;
    }
};
