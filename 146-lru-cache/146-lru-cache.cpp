class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    int capacity;
    unordered_map<int, Node*> hash;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    private:
    void deleteNode(Node* res){
        Node* delPrev = res->prev;
        Node* delNext = res->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
        res->next = NULL;
        res->prev = NULL;
        // delete res;
    }
    
    void addNode(int key, int val){
        Node* temp = new Node(key, val);
        
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
    }
    
    public:
    int get(int key) {
        if(hash.find(key) == hash.end()){
            return -1;
        }
        
        Node* resNode = hash[key];
        int val = resNode->val;
        
        hash.erase(key);
        deleteNode(resNode);
        addNode(key, val);
        hash[key] = head->next;
        
        return val;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            Node* existingNode = hash[key];
            deleteNode(existingNode);
            hash.erase(key);
        }
        
        if(hash.size()==capacity){
            hash.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(key, value);
        hash[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */