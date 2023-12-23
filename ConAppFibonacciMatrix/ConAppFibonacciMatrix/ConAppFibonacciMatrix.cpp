// ConAppFibonacciMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include<bits/stdc++.h> 
using namespace std;

// Helper function that multiplies 2 
// matrices F and M of size 2*2, and 
// puts the multiplication result 
// back to F[][] 
void multiply(int F[2][2], int M[2][2]);

// Helper function that calculates F[][] 
// raise to the power n and puts the 
// result in F[][] 
// Note that this function is designed 
// only for fib() and won't work as 
// general power function 
void power(int F[2][2], int n);

int fib(int n)
{
	int F[2][2] = { { 1, 1 }, { 1, 0 } };

	if (n == 0)
		return 0;

	power(F, n - 1);

	return F[0][0];
}

void multiply(int F[2][2], int M[2][2])
{
	int x = F[0][0] * M[0][0] +
		F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] +
		F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] +
		F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] +
		F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(int F[2][2], int n)
{
	int i;
	int M[2][2] = { { 1, 1 }, { 1, 0 } };

	// n - 1 times multiply the 
	// matrix to {{1,0},{0,1}} 
	for (i = 2; i <= n; i++)
		multiply(F, M);
}

// Driver code 
int main()
{
	int n = 11;

	cout << " " << fib(n);

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
