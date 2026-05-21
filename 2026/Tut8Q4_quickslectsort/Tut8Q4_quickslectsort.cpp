#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr, int low, int high, int pivotIdx = -1) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (i == pivotIdx)
            cout << "[" << arr[i] << "]";
        else if (i >= low && i <= high)
            cout << " " << arr[i] << " ";
        else
            cout << " (" << arr[i] << ")";
    }
    cout << endl;
}

int partition(vector<int>& arr, int low, int high, int step) {
    int pivot = arr[high];
    cout << "\nStep " << step << ": Partition range [" << low << ".." << high << "], pivot = " << pivot << endl;
    cout << "  Before: ";
    printArray(arr, low, high, high);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "  After:  ";
    printArray(arr, low, high, i + 1);
    cout << "  Pivot " << pivot << " placed at index " << (i + 1) << endl;

    return i + 1;
}

int stepCount = 0;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        stepCount++;
        int pi = partition(arr, low, high, stepCount);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {31, 77, 4, 96, 42, 94, 55, 91, 66};
    int n = arr.size();

    cout << "Quick Sort - Step by Step" << endl;
    cout << "==========================" << endl;
    cout << "Initial array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << "(Values in parentheses are outside current partition range)" << endl;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
