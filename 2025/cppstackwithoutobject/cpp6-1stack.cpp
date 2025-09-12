#include <iostream>
using namespace std;

template <class T>
class Stack{
private:
  T *data;
  int sz;
  int tp;
  int capacity;

public:
  Stack()=delete;
  Stack(int cp); 
  Stack(const Stack& ot); 
  Stack(Stack&& ot);

  Stack& operator=(const Stack& ot); 
  bool full();
  bool empty(); 
  bool push(T v); 
  bool pop();
  T top(); 
  int size();
  int getcapacity();
};

template <class T>
Stack<T>::Stack(int cp): sz(0), tp(-1), capacity(cp) {
  data = new T[capacity];
}

template <class T>
Stack<T>::Stack(const Stack& ot): sz(ot.sz), tp(ot.tp), capacity(ot.capacity) {
  data = new T[capacity];
  for (int i = 0; i < sz; i++) {
    data[i] = ot.data[i];
  }
}

template <class T>
Stack<T>::Stack(Stack&& ot): sz(ot.sz), tp(ot.tp), capacity(ot.capacity), data(ot.data) {
  ot.data = nullptr;
  ot.sz = 0;
  ot.tp = -1;
  ot.capacity = 0;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& ot) {
  if (this != &ot) {
    delete[] data;
    sz = ot.sz;
    tp = ot.tp;
    capacity = ot.capacity;
    data = new T[capacity];
    for (int i = 0; i < sz; i++) {
      data[i] = ot.data[i];
    }
  }
  return *this;
}

template <class T>
bool Stack<T>::full() {
  return sz == capacity;
}

template <class T>
bool Stack<T>::empty() {
  return sz == 0;
}

template <class T>
bool Stack<T>::push(T v) {
  if (full()) return false;
  data[++tp] = v;
  sz++;
  return true;
}

template <class T>
bool Stack<T>::pop() {
  if (empty()) return false;
  tp--;
  sz--;
  return true;
}

template <class T>
T Stack<T>::top() {
  if (empty()) throw runtime_error("Stack is empty");
  return data[tp];
}

template <class T>
int Stack<T>::size() {
  return sz;
}

template <class T>
int Stack<T>::getcapacity() {
  return capacity;
}

int main() {
    Stack<int> s(5);
    bool result;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    result = s.push(50);
    if (!result) 
    {
      cout << "Push failed, stack is full." << endl;
    }
    result = s.push(60); // Should fail, stack is full
    if (!result) 
    {
      cout << "Push failed, stack is full." << endl;
    }
    cout << "Top element: " << s.top() << endl; // Should print 20
    cout << "Stack size: " << s.size() << endl; // Should print 2
    s.pop();
    s.pop();
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Should print 10
    return 0;
}
