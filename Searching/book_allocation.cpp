#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > mid) return false;   // single book > limit → impossible

        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m) return false;
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int m) {
    int n = arr.size();
    if (m > n) return -1;   // more students than books

    int start = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) sum += arr[i];

    int end = sum;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    // SAMPLE INPUT:
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int result = findPages(books, students);

    cout << "Minimum pages = " << result << endl;

    return 0;
}
