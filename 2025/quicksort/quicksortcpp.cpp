#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    // Select the rightmost element as pivot
    int pivot = arr[high];
    
    // Pointer for the greater element
    int i = low - 1;
    
    // Traverse through all elements
    // Compare each element with pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            // If element smaller than pivot is found
            // Swap it with the greater element pointed by i
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // Swap the pivot element with the greater element at i
    std::swap(arr[i + 1], arr[high]);
    
    // Return the partition point
    return i + 1;
}

// The main QuickSort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the pivot element such that
        // elements smaller than pivot are on the left
        // elements greater than pivot are on the right
        int pivot = partition(arr, low, high);
        
        // Recursive call on the left of pivot
        quickSort(arr, low, pivot - 1);
        
        // Recursive call on the right of pivot
        quickSort(arr, pivot + 1, high);
    }
}

// Utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Driver code
int main() {
    std::vector<int> data = {8, 7, 6, 1, 0, 9, 2};
    int n = data.size();
    
    std::cout << "Unsorted Array: ";
    printArray(data);
    
    // Perform QuickSort
    quickSort(data, 0, n - 1);
    
    std::cout << "Sorted Array: ";
    printArray(data);
    
    return 0;
}