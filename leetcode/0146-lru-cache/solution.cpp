class LRUCache {
public:
    struct linkedList{
        int val;
        int k;
        linkedList* next = nullptr;
        linkedList* prev = nullptr;
    };
    linkedList* head = nullptr;
    linkedList* tail = nullptr;
    map<int,linkedList*> memo;
    int n = 0;
    int c = 0;

    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(memo.contains(key)){
            linkedList* curr = memo[key];
            if(curr->next == nullptr){
                return curr->val;
            }
            curr->next->prev = curr->prev;
            if(curr->prev != nullptr) curr->prev->next = curr->next;
            head->next = curr;
            curr->prev = head;
            if(curr == tail) tail = tail -> next;
            curr->next = nullptr;
            head = curr;
            return curr->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(memo.contains(key)){
            linkedList* curr = memo[key];
            if(curr != head){
                curr->next->prev = curr->prev;
                if(curr->prev != nullptr) curr->prev->next = curr->next;
                head->next = curr;
                curr->prev = head;
                if(curr == tail) tail = tail -> next;
                curr->next = nullptr;
                head = curr;
            }
            memo[key]->val = value;
        }
        else if(n == 0){
            linkedList* temp = new linkedList();
            temp -> val = value;
            temp -> k = key;
            head = temp;
            tail = temp;
            memo[key] = temp;
            n++;
        }
        else if(c == 1){
            memo.erase(head -> k);
            memo[key] = head;
            head -> val = value;
            head -> k = key;
        }
        else if(!memo.contains(key)){
            if(n == c){
                memo.erase(tail->k);
                tail->next->prev = nullptr;
                tail = tail->next;
                n--;
            }
            linkedList* temp = new linkedList();
                memo[key] = temp;
                temp->val = value;
                temp->k = key;
                head -> next = temp;  
                temp -> prev = head;
                head = temp;
                n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
