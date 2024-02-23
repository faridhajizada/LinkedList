#include <iostream>

class Node{
    public:
        double data;
        Node* next;
     public:
        Node(double data){
            this->data = data;
            this->next = NULL;
        }   
};

class OneLinkedList{
    public:
        Node* head, * tail;
    public:
        OneLinkedList(){
            this->head = this->tail = NULL;
        }
        ~OneLinkedList(){
            while (head!= NULL) pop_front();            
        }

     void push_back(double data){
        Node* node = new Node(data);
        if(head == NULL) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    void push_front(double data){
        Node* node = new Node(data);
        node -> next = head;
        head = node;
        if(tail == NULL) tail = node;
    }

    void pop_front(){
        if(head == NULL) return;
        if(head == tail){
            delete tail;
            head = tail = NULL;
            return;
            }

        Node* node = head;
        head = head->next;
        delete node;    
    } 

    void pop_back(){
        if(tail == NULL) return;
        if(head == tail){
            delete tail;
            head = tail = NULL;
            return;
        }

        Node* node = head;
        while (node->next != tail) {
            node = node->next;
        }
        delete tail;
        tail = node;
        tail->next = NULL;
    }

    Node* find(int k){
        Node* node = head;
        int n = 0;
        while(node && n != k && node->next){
           node = node->next;
           n++;
       }
        return (n == k) ? node : NULL;
    }

    void insert(int k, double data){
        Node* left = find(k);
        if(left == NULL) return;
        Node* right = left->next;
        Node* node = new Node(data);
        left->next = node;
        node->next = right;
        if(left == tail) tail = node;  
    }

    void erase(int k){
        if(k < 0) return;
        if(k == 0) {
            pop_front();
            return;
        }
        Node* left = find(k-1);
        Node* node = left->next;
        if(node == NULL) return;
        Node* right = node->next;

        left->next = right;
        if(node == tail) tail = left;
        delete node;
    } 

    int size(){
        Node* node = head;
        int n = 0;
        while(node){
            node = node->next;
            n++;
        }
        return n;
    }
    void clear(){
        while(head != NULL) pop_front();
    }
};

int main(){
    OneLinkedList list;
    list.push_front(4.4);
    list.push_back(1.1);
    list.push_back(2.2);
    list.push_back(3.3);
    list.pop_back();
    list.pop_front();
    list.insert(0, 99);
    list.erase(1);

    Node* n =list.find(0);
    double d = (n != NULL) ? n->data : 0;
    std::cout << "find: " << d << std::endl;
  

    for(Node* node = list.head; node != NULL; node = node->next){
        std::cout << node->data << ", ";
    }
    std::cout << std::endl;

    return 0;
}