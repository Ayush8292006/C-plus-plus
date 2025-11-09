#include <iostream>
using namespace std;

void merge(int* arr, int s, int e) {

    int mid = (s + e) / 2;

    int l1 = mid - s + 1;
    int l2 = e - mid;

    int* left = new int[l1];
    int* right = new int[l2];

    // copy left
    int k = s;
    for (int i = 0; i < l1; i++) {
        left[i] = arr[k++];
    }

    // copy right
    k = mid + 1;
    for (int i = 0; i < l2; i++) {
        right[i] = arr[k++];
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;

    while (leftIndex < l1 && rightIndex < l2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainIndex++] = left[leftIndex++];
        } else {
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    // remaining left
    while (leftIndex < l1) {
        arr[mainIndex++] = left[leftIndex++];
    }

    // remaining right
    while (rightIndex < l2) {
        arr[mainIndex++] = right[rightIndex++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int s, int e) {

    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    // left sort
    mergeSort(arr, s, mid);

    // right sort
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

int main() {

    int arr[] = {2, 1, 12, 13, 11, 10};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
