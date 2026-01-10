#include <iostream>

using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    
    //Node(int value) : data(value), next(nullptr) {}
    // Node()
    // {
    //     data = 0;
    //     next = nullptr;
    // }

    Node(int value = 0) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;
    
public:
    //LinkedList() : head(nullptr) {}
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        clear();
    }
    
    // Insert at end
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
    
    // Insert after a specific value
    bool insertAfter(int afterValue, int newValue) {
        Node* current = head;
        
        // Find the node with the specified value
        while (current != nullptr) {
            if (current->data == afterValue) {
                Node* newNode = new Node(newValue);
                newNode->next = current->next;
                current->next = newNode;
                return true;
            }
            current = current->next;
        }
        return false; // Value not found
    }
    
    // Display the list
    void display() {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
    
    // Clear the list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    //Node* node = new Node();
    LinkedList list;
    
    cout << "=== Single Linked List Insert After Demo ===" << endl << endl;
    
    // Insert 1, 2, 3, 4, 5
    cout << "Inserting: 1, 2, 3, 4, 5" << endl;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    
    list.display();
    
    // Insert 6 after 3
    cout << "\nInserting 6 after 3..." << endl;
    if (list.insertAfter(3, 6)) {
        cout << "Successfully inserted 6 after 3" << endl;
    } else {
        cout << "Failed to insert - value 3 not found" << endl;
    }
    
    list.display();
    
    cout << "\n=== Complete ===" << endl;
    
    return 0;
}
