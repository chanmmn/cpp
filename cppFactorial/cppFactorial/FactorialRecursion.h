#pragma once
#include <iostream>
using namespace std;

unsigned int factorialRecursion(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursion(n - 1);
}

//int main()
//{
//    int num = 5;
//    cout << "Factorial of "
//        << num << " is: " << factorial(num) << endl;
//    return 0;
//}
