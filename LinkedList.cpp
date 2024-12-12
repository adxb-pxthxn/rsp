#include <iostream>
class Node
{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

};

class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* current = head->next;
        int i = 0;
        while (current) {
            if (i == index) {
                return current->data;
            }
            current = current->next;
            i++;
        }
    }

    void insertHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head->next;
        head->next = newNode;
        if(newNode->next == nullptr){
            tail = newNode;
        }
    }
    
    void insertTail(int val){
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        Node* curr = head; 
        while (i < index && curr != nullptr) {
            curr = curr->next;
            i++;
        }

        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr;  
            }
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }
};

int main() {
    LinkedList list;

    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);

    list.insertTail(40);
    list.insertTail(50);

    std::cout << "index 0: " << list.get(0) << std::endl; 
    std::cout << "index 2: " << list.get(2) << std::endl; 
    std::cout << "index 4: " << list.get(4) << std::endl; 

    if (list.remove(2)) {
        std::cout << "removed successfully" << std::endl;
    } else {
        std::cout << "Failed to remove element" << std::endl;
    }

    std::cout << "index 2: " << list.get(2) << std::endl;

    return 0;
}