#include <iostream>
using namespace std;

class Category {
public:
  int id;
  string name;

  Category() : id(0), name("") {}
  Category(int i, string n) : id(i), name(n) {}
};
class Product {
public:
  int id;
  string name;
  float price;
  Category category;

  Product() : id(0), name(""), price(0.0), category() {}
  Product(int i, string n, float p, Category c) : id(i), name(n), price(p), category(c) {}
};

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
  //data = new T[capacity];
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
    //Stack<int> s(5);
    Stack<Product> s(5);
    bool result;
    Product p = Product(1, "Product 1", 10.0, Category(1, "Category 1"));
    s.push(p);
    //s.push(Product(1, "Product 1", 10.0, Category(1, "Category 1")));
    s.push(Product(2, "Product 2", 20.0, Category(2, "Category 1")));
    s.push(Product(3, "Product 3", 30.0, Category(3, "Category 3")));
    s.push(Product(4, "Product 4", 40.0, Category(4, "Category 4")));
    result = s.push(Product(5, "Product 5", 50.0, Category(5, "Category 5")));
    //result = s.push(50);
    if (!result) cout << "Push failed, stack is full." << endl;
    result = s.push(Product(6, "Product 6", 60.0, Category(6, "Category 6")) ); // Should fail, stack is full
    if (!result) cout << "Push failed, stack is full." << endl;
    cout << "Top element: " << s.top().name << endl; // Should print "Product 5"
    cout << "Top category: " << s.top().category.name << endl; // Should print "Product 5"
    cout << "Stack size: " << s.size() << endl; // Should print 5
    s.pop();
    s.pop();
    cout << "Top element after pop: " << s.top().name << endl; // Should print "Product 4"
    return 0;
} 
