// struct ListNode {
//       int val;
//       ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
class MyCircularQueue {
private:
    ListNode* head = nullptr;
    int num = 0;
    int count = 0;
public:
    MyCircularQueue(int k) {
        num = k;
    }
    
    bool enQueue(int value) {
        //cout << "enqueue" << count << num <<endl;
        if(count == num) return false;
        if(count == 0) head = new ListNode(value);
        else{
            ListNode* t = new ListNode(value , head -> next);
            if(t -> next == nullptr) t -> next = head;
            head -> next = t;
            head = t;
        }
        count++;
        //cout << count << num <<endl;
        return true;
    }
    
    bool deQueue() {
        //cout << count << num <<endl;
        if(count == 0) return false;
        else if(count == 1){
            count--;
            head = nullptr;
            return true;
        }else{
            count--;
            head -> next = head -> next -> next;
            return true;
        }
    }
    
    int Front() {
        if(head == nullptr) return -1;
        else if(head -> next == nullptr) return head -> val;
        else return head -> next -> val;
    }
    
    int Rear() {
        if(head == nullptr) return -1;
        else return head -> val;
    }
    
    bool isEmpty() {
        if(head == nullptr) return true;
        else return false;
    }
    
    bool isFull() {
        if(count == num) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */ 
