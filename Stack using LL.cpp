#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Stack{
    Node* head;
    public:
    Stack(){
        head = nullptr;
    }
        

    void push(int val){
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }
    void pop(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    bool isempty(){
        return head == nullptr;
    }

    int top(){
        if (head == nullptr) {
            throw runtime_error("Stack is empty");
        }   
        return head->data;
    }
};



int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.top();
}