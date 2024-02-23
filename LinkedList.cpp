#include <iostream>

class Node{
    public:
        double data;
        Node* prev;
        Node* next;
    public:
    Node(double data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }  
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
    public:
        LinkedList(){ 
            head = NULL;
            tail = NULL;
        }

        ~LinkedList(){
            while(head != NULL) pop_front();
        }

        Node* push_front(double data){
            Node* node = new Node(data);
            node->next = head;
            if(head != NULL) head->prev = node;
            if(tail == NULL) tail = node;
            head = node;
            return node;
        }

        Node* push_back(double data){
            Node* node = new Node(data);
            tail->next = node;
            node->prev = tail;
            tail = node;
            return node;    
        }

        void pop_front(){
            if(head == NULL) return;
            if(head == tail){
                delete tail;
                head = tail = NULL;
                return;
            }
            Node* node = head->next;
            if(node != NULL) node->prev = NULL;
            delete head;
            head = node;

        }

        void pop_back(){
           if(tail == NULL) return;
           if(head == tail){
            head = tail = NULL;
            delete tail;
            return;
           } 
              Node* node = tail->prev;  
                if(node != NULL) node->next = NULL;
                delete tail;
                tail = node;
        }

        Node* find(int index){
            Node* node = head;
            int n = 0;
            while(n != index){
                if(node == NULL) return node;
                node = node->next;
                n++;
            }
        return node;
    }

        Node* operator [] (int index){
        return find(index);
    }

        Node* insert(int index, double data){
        Node* right = find(index);
        if(right == NULL) return NULL;
        Node* left = right->prev;
        Node* node = new Node(data);
        node->prev = left;
        node->next = right;
        if(left != NULL) left->next = node;
        if(right != NULL) right->prev = node;
        if(head == right) head = node;
        return node;
    }

        void erase(int index){
            Node* node = find(index);
            if(node == NULL) return;
            Node* left = node->prev;
            Node* right = node->next;
            if(left != NULL) left->next = right;
            if(right != NULL) right->prev = left;
            if(head == node) head = right;
            if(tail == node) tail = left;
            delete node;    
         }


};

int main(){
    LinkedList list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(99);
    list.pop_back();
    list.pop_front();
    list.insert(0, 4.4);
    list.erase(1);

    for(Node* node = list.head; node != NULL; node = node->next){
        std::cout << node->data << std::endl;
    }

    return 0;
}