#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int rows, int cols, int target) {
    int start = 0;
    int end = rows * cols - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // keep inside loop
        int rowIndex = mid / cols;
        int colIndex = mid % cols;

        int element = arr[rowIndex][colIndex];

        if (element == target) {
            cout << "Found at row " << rowIndex << ", col " << colIndex << endl;
            return true;  // ✅ return true immediately
        }
        else if (target < element) {
            end = mid - 1; // go left
        }
        else {
            start = mid + 1; // go right
        }
    }

    return false; // not found
}

int main() {
    int arr[5][4] = { 
        {1,2,3,4}, 
        {5,6,7,8}, 
        {9,10,11,12}, 
        {13,14,15,16}, 
        {17,18,19,20} 
    };
    int rows = 5;
    int cols = 4;
  
    int target = 19;

    bool ans = binarySearch(arr, rows, cols, target);

    if (ans) 
        cout << "Target found " << endl;
    else 
        cout << "Not found " << endl;

    return 0;
}
