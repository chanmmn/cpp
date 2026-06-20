#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Fibonacci terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    vector<long long> dp(n);
    dp[0] = 0;
    if (n > 1) dp[1] = 1;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci sequence:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "F(" << i << ") = " << dp[i] << endl;
    }

    return 0;
}
