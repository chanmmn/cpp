#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }    
       
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    // Display the linked list
    void display() {
        Node* current = head;
        std::cout << "Linked List: ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Get the size of the linked list
    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    
    // Insert some values
    list.insertAtEnd(10);
    list.insertAtEnd(20);

    list.insertAtEnd(25);
    
    // Display the list
    list.display();
    std::cout << "Size: " << list.size() << std::endl;
        
    list.display();
    std::cout << "Size: " << list.size() << std::endl;
    
    return 0;
}