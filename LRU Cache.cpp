#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    int data;
    int key;
    Node* next;
    Node* prev;

    Node(int v, int k){
        this->data = v;
        this->key = k;
        next = nullptr;
        prev = nullptr;
    }
};

class LRU{

    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int lim;
public:
    LRU(int cap){
        lim = cap;
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;        
    }

    int get(int key){
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* node = m[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;

    return node->data;
    }

    void removenode(){
        if (head->next == tail) {
            return;
        }
        Node* temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        temp->next = nullptr;
        m.erase(temp->key);
        delete temp;
    }
    void addnode(int key, int val){
        Node* newnode = new Node(val, key);
        newnode->next = head->next;
        newnode->prev = head;
        if (head->next) {            
            head->next->prev = newnode;  
        }
        head->next = newnode;
        m[key] = newnode;
    }

    void put(int key, int val){
        if(m.find(key) != m.end()){
            Node* node = m[key];
            node->data = val;
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head->next;
            node->prev = head;
            node->next->prev = node;
            head->next = node;
        }
    else{
        if(m.size() == lim){
            removenode();          
        }
        addnode(key, val);
    }
    }
};


int main(){

    LRU cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl;

    cache.put(3, 30);
    cout << cache.get(2) << endl;

    cache.put(4, 40);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;

}