#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void candidate_helper(vector<int>& candidates, int target, vector<int>& v,
                      vector<vector<int>>& ans , int index) {

    // base
    if (target == 0) {
        ans.push_back(v);
        return;
    }
    if (target < 0) return;

    for (int i = index; i < candidates.size(); i++) {

        // skip duplicates
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        v.push_back(candidates[i]);
        candidate_helper(candidates, target - candidates[i], v, ans, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> v;
    candidate_helper(candidates, target, v, ans, 0);
    return ans;
}

int main() {
    vector<int> candidates{2, 5, 2, 1, 2};
    sort(candidates.begin(), candidates.end()); 
    int target = 5;

    vector<vector<int>> result = combinationSum2(candidates, target);

    for (int i = 0; i < result.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }
}
