#pragma once
#include <iostream>
using namespace std;

int factorialTernary(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorialTernary(n - 1);
}

//int main()
//{
//    int num = 5;
//    cout << "Factorial of " << num << " is " << factorial(num);
//    return 0;
//}
