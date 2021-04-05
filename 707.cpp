class MyLinkedList {
public:
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode():val(0),next(nullptr){};
        LinkNode(int val):val(val),next(nullptr){};
        LinkNode(int val,LinkNode *next):val(val),next(next){}
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummyHead = new LinkNode();
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=_size)return -1;
        else{
            LinkNode *p=_dummyHead;
            while(index-->=0){
                p = p->next;                
            }
            return p->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode *p = new LinkNode(val,_dummyHead->next);
        _dummyHead->next = p;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkNode *p = _dummyHead;
        for(int i=0;i<_size;i++){
            p = p->next;
        }
        p->next = new LinkNode(val);
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>_size){
            return;
        }
        if(index<0){
            index=0;
        }
        LinkNode *p = _dummyHead;
        for(int i=0;i<index;i++){
            p = p->next;
        }
        LinkNode *q = new LinkNode(val,p->next);
        p->next = q;
        _size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=_size){
            return;
        }
        LinkNode *p = _dummyHead;
        while(index-->0){
            p = p->next;
        }
        LinkNode *q = p->next;
        p->next = p->next->next;
        delete q;
        _size--;
    }

    private:
    int _size;
    LinkNode *_dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */