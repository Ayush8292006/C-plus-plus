#include <iostream>
#include <vector>
using namespace std;

void printAllSubarray_util(vector<int>& nums, int start, int end) {
    // base case: when end reaches beyond the last index
    if (end == nums.size()) {
        return;
    }

    // print one subarray
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // recursive call for next subarray (increasing end)
    printAllSubarray_util(nums, start, end + 1);
}

void printAllSubarray(vector<int>& nums) {
    // fix start and move end using recursion
    for (int start = 0; start < nums.size(); start++) {
        int end = start;
        printAllSubarray_util(nums, start, end);
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    printAllSubarray(nums);   
    return 0;
}
