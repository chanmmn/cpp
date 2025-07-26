#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyList {
private:
  struct Node{
    T value;
    Node *next;
  };

  Node *head;
  int sz;

  void *getNew(T d);
  void *search(T);
  void *movetoend();
 
public:
  MyList();
  void push_back(T);
  void push_front(T);
  void insert(T);
  bool insert(int,T);
  bool deleteNode(T);
  void print() const;
  int size();
  ~MyList();
};

template<class T>
MyList<T>::MyList() {
  head = nullptr;
  sz = 0;
}
template<class T>
void *MyList<T>::getNew(T d) {
  Node *newNode = new Node;
  newNode->value = d;
  newNode->next = nullptr;
  return newNode;
}
template<class T>
void MyList<T>::push_back(T d) {
  Node *newNode = static_cast<Node *>(getNew(d));
  if (head == nullptr) {
    head = newNode;
  } else {
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
  sz++;
}
template<class T>
void MyList<T>::push_front(T d) {
  Node *newNode = static_cast<Node *>(getNew(d));
  newNode->next = head;
  head = newNode;
  sz++;
}
template<class T>
void MyList<T>::insert(T d) {
  Node *newNode = static_cast<Node *>(getNew(d));
  if (head == nullptr || head->value >= d) {
    newNode->next = head;
    head = newNode;
  } else {
    Node *current = head;
    while (current->next != nullptr && current->next->value < d) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
  sz++;
}
template<class T>
bool MyList<T>::insert(int pos, T d) {
  if (pos < 0 || pos > sz) return false;
  Node *newNode = static_cast<Node *>(getNew(d));
  if (pos == 0) {
    newNode->next = head;
    head = newNode;
  } else {
    Node *current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; i++) {
      current = current->next;
    }
    if (current == nullptr) return false;
    newNode->next = current->next;
    current->next = newNode;
  }
  sz++;
  return true;
}
template<class T>
bool MyList<T>::deleteNode(T d) {
  if (head == nullptr) return false;
  if (head->value == d) {
    Node *temp = head;
    head = head->next;
    delete temp;
    sz--;
    return true;
  }
  Node *current = head;
  while (current->next != nullptr && current->next->value != d) {
    current = current->next;
  }
  if (current->next == nullptr) return false;
  Node *temp = current->next;
  current->next = current->next->next;
  delete temp;
  sz--;
  return true;
}
template<class T>
void MyList<T>::print() const {
  Node *current = head;
  while (current != nullptr) {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
}
template<class T>
int MyList<T>::size() {
  return sz;
}               
template<class T>
MyList<T>::~MyList() {
  Node *current = head;
  while (current != nullptr) {
    Node *temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  sz = 0;
}
int main() {
  MyList<string> list;
  list.push_back("Alice");
  list.push_back("Bob");
  list.push_front("Charlie");
  list.insert("David");
  list.insert(2, "Eve");
  
  cout << "List after insertions: ";
  list.print();
  
  cout << "Size of the list: " << list.size() << endl;

  list.deleteNode("Bob");
  cout << "List after deleting 'Bob': ";
  list.print();

  return 0;
}

