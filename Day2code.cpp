#include <iostream>
using namespace std;

// Function to find the first occurrence of x
int firstOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            result = mid;
            high = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to find the last occurrence of x
int lastOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            result = mid;
            low = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to count occurrences of x
int countOccurrences(int arr[], int n, int x) {
    int first = firstOccurrence(arr, n, x);
    if (first == -1) return 0; // x not found

    int last = lastOccurrence(arr, n, x);
    return last - first + 1;
}

int main() {
    int arr[] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    cout << "Enter the number to count: ";
    cin >> x;

    int count = countOccurrences(arr, n, x);
    cout << "Number of occurrences of " << x << ": " << count << endl;

    return 0;
}