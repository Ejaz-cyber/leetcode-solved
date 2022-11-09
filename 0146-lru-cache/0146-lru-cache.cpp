class LRUCache {
public:
    // DCLL
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);
    
    int cap;    // capacity
    unordered_map<int, node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node * newNode){
        node* temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node * delNode){
        node * delprev = delNode->prev;
        node * delnext = delNode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node * resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node * existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key, value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */