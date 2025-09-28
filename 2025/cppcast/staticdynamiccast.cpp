#include <iostream>
using namespace std;
class Base {
public:
    virtual void show() { cout << "Base class\n"; }
};
class Derived : public Base {
public:
    void show() override { cout << "Derived class\n"; }
    void derivedFunc() { cout << "Derived specific function\n"; }
};
int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr1 = static_cast<Derived*>(basePtr);
    derivedPtr1->show();
    derivedPtr1->derivedFunc();
    Base* basePtr2 = new Base();
    Derived* derivedPtr2 = dynamic_cast<Derived*>(basePtr2);
    if (derivedPtr2) {
        derivedPtr2->show();
        derivedPtr2->derivedFunc();
    } else {
        cout << "dynamic_cast failed: basePtr2 is not a Derived\n";
    }
    delete basePtr;
    delete basePtr2;
    return 0;
}
