class LinkedList{
public:
    LinkedList* next;LinkedList* prev;
    int val;int key;

    LinkedList(int k,int x): val(x),key(k){
    }
};

class LRUCache {
public:
    unordered_map<int, LinkedList*> mp;
    LinkedList* root;LinkedList* last;
    int cap;
    
    LRUCache(int capacity) {
        root=NULL;last=NULL;cap=capacity;
    }
    
    void moveToFront(LinkedList* temp){
        if (temp!=root && temp!=last){temp->prev->next=temp->next;temp->next->prev=temp->prev;}
        else if (temp==last){return;}
        else if (temp==root){temp->next->prev=NULL;root=temp->next;}
        if (temp!=last)last->next=temp;temp->prev=last;
        last=temp;
    }
    
    int get(int key) {
        if (mp.find(key)!=mp.end()){
            LinkedList* temp=mp[key];
            moveToFront(temp);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            mp[key]->val = value;
            LinkedList* temp=mp[key];
            moveToFront(temp);
        }
        else{
            mp[key]= new LinkedList(key,value);
            if (root==NULL){
                root=mp[key];last=mp[key];
            }
            else{
                last->next=mp[key];mp[key]->prev=last;last=mp[key];
                if (mp.size()>cap){
                    mp.erase(root->key);
                    root=root->next;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */