#pragma once
#include <iostream>
using namespace std;

unsigned int factorialLoop(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

//int main()
//{
//    int num = 5;
//    cout << "Factorial of "
//        << num << " is "
//        << factorial(num) << endl;
//    return 0;
//}