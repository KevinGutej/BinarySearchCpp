#include <iostream>
#include <vector>
#include <algorithm>  // For sorting the array

using namespace std;

// Binary search function, returns the index of the found element or -1 if not found
int binarySearch(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;  // Set the start (left) and end (right) of the search range

    while (left <= right) {  // Continue as long as the search range is not empty
        int mid = left + (right - left) / 2;  // Calculate the middle index

        if (arr[mid] == x) {  // If we found the target element
            return mid;  // Return its index
        }
        if (arr[mid] < x) {  // If the middle element is smaller than x
            left = mid + 1;  // Search in the right half (ignore the left part)
        } else {  // If the middle element is greater than x
            right = mid - 1; // Search in the left half (ignore the right part)
        }
    }
    return -1;  // If the element is not found, return -1
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;  // Read the size of the array

    if (n <= 0) {  // Check for invalid input size
        cout << "Invalid array size. Please enter a positive number." << endl;
        return 1;
    }

    vector<int> numbers(n);  // Pre-allocate vector with the given size

    cout << "Enter the elements (separated by spaces): ";
    for (int i = 0; i < n; ++i) {  // Read user input elements
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());  // Sort the array to ensure binary search works correctly
    cout << "Sorted Array: ";
    for (int num : numbers) {  // Print the sorted array
        cout << num << " ";
    }
    cout << endl;

    cout << "Enter the element to search for: ";
    cin >> target;  // Read the target element to search

    int result = binarySearch(numbers, target);  // Call the binary search function

    if (result != -1) {  // If the function returned an index (element found)
        cout << "Found element " << target << " at index: " << result << endl;
    } else {  // If the function returned -1 (element not found)
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
