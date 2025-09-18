#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it's possible to cook n pratas in <= mid minutes
bool isPossSolution(vector<int>& arr, int n, int k, int mid) {
    int timeSum = 0;
    int c = 1; // number of partitions/workers
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;
        }
        if (arr[i] + timeSum > mid) {
            c++;
            timeSum = arr[i];
            if (c > k) return false;
        } else {
            timeSum += arr[i];
        }
    }
    return true;
}

int minTime(vector<int>& arr, int k) {
    int n = arr.size();
    int s = 0;
    int e = 0;

    for (int i = 0; i < n; i++) {
        e += arr[i];
    }

    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossSolution(arr, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;   // first input: size of array, second: k workers
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minTime(arr, k) << endl;
    return 0;
}
