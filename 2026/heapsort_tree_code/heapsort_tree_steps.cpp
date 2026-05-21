#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArray(const vector<int>& arr) {
	for (int value : arr) {
		cout << value << " ";
	}
	cout << '\n';
}

void printHeapTree(const vector<int>& arr, int heapSize) {
	if (heapSize <= 0) {
		cout << "(empty heap)\n";
		return;
	}

	int levels = static_cast<int>(floor(log2(heapSize))) + 1;
	int index = 0;

	for (int level = 0; level < levels; ++level) {
		int nodesOnLevel = 1 << level;
		int firstGap = 1 << (levels - level);
		int betweenGap = 1 << (levels - level + 1);

		cout << string(firstGap, ' ');

		for (int j = 0; j < nodesOnLevel && index < heapSize; ++j, ++index) {
			cout << setw(3) << arr[index];
			if (j < nodesOnLevel - 1) {
				cout << string(betweenGap, ' ');
			}
		}
		cout << '\n';
	}
}

void heapify(vector<int>& arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSortWithSteps(vector<int>& arr) {
	int n = static_cast<int>(arr.size());

	cout << "Step 0: Initial array\n";
	printArray(arr);
	cout << "Tree:\n";
	printHeapTree(arr, n);
	cout << "\n";

	cout << "=== Build Max Heap ===\n";
	for (int i = n / 2 - 1, step = 1; i >= 0; --i, ++step) {
		heapify(arr, n, i);
		cout << "Build step " << step << " (heapify at index " << i << ")\n";
		printArray(arr);
		cout << "Tree:\n";
		printHeapTree(arr, n);
		cout << "\n";
	}

	cout << "=== Extract Max and Re-heapify ===\n";
	for (int i = n - 1, step = 1; i > 0; --i, ++step) {
		swap(arr[0], arr[i]);
		cout << "Extract step " << step << ": swap root with index " << i << "\n";
		cout << "Array: ";
		printArray(arr);
		cout << "Heap part tree (size " << i << "):\n";
		printHeapTree(arr, i);
		cout << "Sorted part: ";
		for (int j = i; j < n; ++j) {
			cout << arr[j] << " ";
		}
		cout << "\n\n";

		heapify(arr, i, 0);
		cout << "After re-heapify (heap size " << i << ")\n";
		cout << "Array: ";
		printArray(arr);
		cout << "Heap part tree:\n";
		printHeapTree(arr, i);
		cout << "Sorted part: ";
		for (int j = i; j < n; ++j) {
			cout << arr[j] << " ";
		}
		cout << "\n\n";
	}
}

int main() {
	vector<int> arr = {38, 9, 38, 37, 155, 197, 65};

	heapSortWithSteps(arr);

	cout << "Final sorted array: ";
	printArray(arr);

	return 0;
}
