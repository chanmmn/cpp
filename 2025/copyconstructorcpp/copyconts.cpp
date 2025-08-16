#include <iostream>
#include <cstring>
class MyString {
private:
    char* str;
public:
    // Constructor
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    // Destructor
    ~MyString() {
        delete[] str;
    }
    // Assignment operator overload
    MyString& operator=(const MyString& other) {
        // Check for self-assignment
        if (this != &other) {
            // Delete existing data
            delete[] str;
            // Allocate new memory and copy
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    // Display string
    void display() const {
        std::cout << str << std::endl;
    }
};
int main() {
    MyString s1("Hello");
    MyString s2;
    s2 = s1;  // Uses overloaded assignment operator
    std::cout << "s1: ";
    s1.display();
    std::cout << "s2: ";
    s2.display();
    // Self-assignment test
    s1 = s1;
    std::cout << "After self-assignment: ";
    s1.display();
    return 0;
}
