

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start)/2;
        int element = arr[mid];

        if (element == target) 
            return mid; // target mil gaya
        else if (target < element) 
            end = mid - 1; // left side jao
        else 
            start = mid + 1; // right side jao
    }
    return -1; // not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 16};
    int size = 7;
    int target = 12;

    int indexOfTarget = binarySearch(arr, size, target);

    if (indexOfTarget == -1) 
        cout << "Target not found";
    else 
        cout << "Target found at index " << indexOfTarget << endl;

    return 0;
}
