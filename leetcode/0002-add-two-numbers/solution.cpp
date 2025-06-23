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
        stack<int>s3;
       
        int n1 , n2 ,n3 = 0;
        while(l1!= nullptr || l2!= nullptr){
            
            if(l1!= nullptr){
                n1 = l1 -> val;
                l1 = l1 -> next;
            }
            else{
                n1 = 0;
            }
            if(l2 != nullptr){
                n2 = l2 -> val;
                l2 = l2 -> next;
            }
            else{
                n2 = 0;
            }
            n3 = n1+n2+n3;
            s3.push(n3%10);
            n3/=10;
        }
        while(n3!= 0){
            s3.push(n3%10);
            n3/=10;
        }
        ListNode* head = new ListNode(s3.top());
        s3.pop();
        while(!s3.empty()){
            ListNode* temp = new ListNode(s3.top());
            s3.pop();
            temp -> next = head;
            head = temp;
        }
        return head;
    }
};
