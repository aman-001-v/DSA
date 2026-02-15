/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* ohead = head;
        unordered_map < Node* , Node*> memo;
        Node* newHead = new Node(head -> val);
        memo[head] = newHead;
        Node* rHead = newHead;
        while(head != nullptr && newHead != nullptr){
            if(head -> next != nullptr){
                    Node* temp = new Node(head -> next -> val);
                    newHead -> next = temp;
                    memo[head -> next] = temp;
                }
            head = head -> next;
            newHead = newHead -> next;
        }
        head = ohead;
        newHead = rHead;
        while(head != nullptr && newHead != nullptr){
            if(head -> random != nullptr){
                newHead -> random = memo[head -> random];
            }
            head = head -> next;
            newHead = newHead -> next;
        }
        return rHead;
    }
};
