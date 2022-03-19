// Idea is for each frequency we have separate LRU.
class Node {
public:
    int key, value, count;
    Node* next;
    Node* prev;
    Node (int k, int v, int ct = 1) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
        count = ct;
    }
};

class List {
public:
    int size;
    Node *head;
    Node *tail;
    
    List() {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *curr) {
        curr->prev = head;
        curr->next = head->next;
        head->next = curr;
        curr->next->prev = curr;
        size++;
    }
    
    void deleteNode(Node *curr) {
        Node* temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete temp;
        size--;
    }
};

// LFU Implementation
class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxCacheSize, currSize, minFreq;
public:
    
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateFreqListMap(Node* curr) {
        keyNode.erase(curr->key);
        Node* newNode = new Node(curr->key, curr->value, curr->count);
        freqListMap[curr->count]->deleteNode(curr);
        
        if(newNode->count == minFreq and freqListMap[newNode->count]->size == 0)
            minFreq++;
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(newNode->count + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[newNode->count + 1];
        }
        else 
        freqListMap[newNode->count+1] = nextHigherFreqList;
        
        newNode->count += 1;
        nextHigherFreqList->addNode(newNode);
        keyNode[newNode->key] = newNode;
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        Node* curr = keyNode[key];
        int val = curr->value;
        updateFreqListMap(curr);
        return val;
    }
    
    void put(int key, int value) {
        if(maxCacheSize == 0) return;
        if(keyNode.find(key) != keyNode.end()) {
            Node* curr = keyNode[key];
            curr->value = value;
            updateFreqListMap(curr);
        }
        else {
            if(currSize == maxCacheSize) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }
            
            currSize++;
            minFreq = 1;
            List* listLRU = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listLRU = freqListMap[minFreq];
            }
            
            Node* newNode = new Node(key, value);
            listLRU->addNode(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = listLRU;
        }
    }
};