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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = new ListNode(0 , l1);
        ListNode* t2 = new ListNode(0, l2);
        l1 = t1;
        l2 = t2;
        int carry = 0;
        while(l1 -> next != nullptr && l2 -> next != nullptr){
            int temp = l1 -> next -> val + l2 -> next -> val + carry;
            l1 -> next -> val = temp % 10;
            l2 -> next -> val = temp % 10;
            carry = temp / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(l1 -> next != nullptr){  
            while(l1 -> next != nullptr){
                int temp = l1 -> next -> val + carry;
                l1 -> next -> val = temp %10;
                carry = temp /10;
                l1 = l1 -> next;
            }
            while(carry != 0){
                        ListNode* t = new ListNode(carry%10);
                        l1 -> next = t;
                        carry /= 10;
                        l1 = l1 -> next;
                    }
            return t1 -> next;
        }
        if(l2 -> next != nullptr){
            while(l2 -> next != nullptr){
                int temp = l2 -> next -> val + carry;
                l2 -> next -> val = temp % 10;
                carry = temp / 10;
                l2 = l2 -> next;
            }
            while(carry != 0){
                        ListNode* t = new ListNode(carry%10);
                        l2 -> next = t;
                        carry /= 10;
                        l2 = l2 -> next;
                    }
            return t2 -> next;

        }
        while(carry != 0){
            ListNode* t = new ListNode(carry%10);
            l1 -> next = t;
            carry /= 10;
            l1 = l1 -> next;
        }
        return t1 -> next;
    }
};
