#include <bits/stdc++.h>
using namespace std;

int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> merged;
    int i = 0, j = 0;

    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
        else merged.push_back(nums2[j++]);
    }

    while(i < nums1.size()) merged.push_back(nums1[i++]);
    while(j < nums2.size()) merged.push_back(nums2[j++]);

    int n = merged.size();

    if(n % 2 == 1)     // odd
        return merged[n/2];

    return (merged[n/2] + merged[n/2 - 1]) / 2.0;
}

int main() {
    vector<int> nums1 = {1, 3,4,7,10,12};
    vector<int> nums2 = {2,3,6,15};

    int ans = findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << ans << endl;

    return 0;
}
