class Node{
    public:
    int key, val, cnt;
    Node* next;
    Node* prev;
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;
    
    List() {
        head = new Node(0,0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNode(Node* node){
        Node* temp = head->next;  
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    
    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
        delNode->next = NULL;
        delNode->prev = NULL;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqList;
    
    int maxSizeCache;
    int minFreq;
    int currSize;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
private:
    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->deleteNode(node);
        if(minFreq==node->cnt && freqList[node->cnt]->size==0){
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        if(freqList.find(node->cnt + 1) != freqList.end()){
            nextHigherFreqList = freqList[node->cnt + 1];
        }
        
        node->cnt += 1;
        nextHigherFreqList->addNode(node);
        freqList[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
public:    
    int get(int key) {
        if(keyNode.find(key)==keyNode.end()){
            return -1;
        }
        
        Node* node = keyNode[key];
        int val = node->val;
        updateFreqList(node);
        return val;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0){
            return;
        }
        
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        } else {
            if(currSize==maxSizeCache){
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }
            
            currSize++;
            minFreq = 1;
            List* list = new List();
            if(freqList.find(minFreq)!=freqList.end()){
                list = freqList[minFreq];
            }
            
            Node* node = new Node(key, value);
            list->addNode(node);
            freqList[minFreq] = list;
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */