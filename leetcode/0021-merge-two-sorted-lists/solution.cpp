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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* temp = head;
        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> val < list2 -> val){
                ListNode* temp1 = new ListNode(list1-> val);
                temp -> next = temp1;
                temp = temp1;
                list1 = list1 -> next;
            }
            else{
                ListNode* temp1 = new ListNode(list2-> val);
                temp -> next = temp1;
                temp = temp1;
                list2 = list2 -> next;
            }
            }
            while(list1 != nullptr){
            ListNode* temp1 = new ListNode(list1-> val);
                temp -> next = temp1;
                temp = temp1;
                list1 = list1 -> next;
        }
        while(list2 != nullptr){
            ListNode* temp1 = new ListNode(list2 -> val);
                temp -> next = temp1;
                temp = temp1;
                list2 = list2 -> next;
        }
        head = head -> next;
        return head;
        
        
    }
};
