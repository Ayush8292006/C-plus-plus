#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void permuteUniqueHelper(vector<int>& nums, vector<vector<int>>& ans, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;

        for (int i = start; i < nums.size(); i++) {

            // skip duplicates on this level
            if (visited.find(nums[i]) != visited.end()) {
                continue;
            }

            visited[nums[i]] = true;

            swap(nums[i], nums[start]);
            permuteUniqueHelper(nums, ans, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUniqueHelper(nums, ans, 0);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> result = s.permuteUnique(nums);

    for (auto& vec : result) {
        cout << "[ ";
        for (auto val : vec) cout << val << " ";
        cout << "]\n";
    }
}
