#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if it's possible to cook nP pratas in <= mid minutes
bool isPossibleSolution(const vector<int>& cooksRank, int nP, int mid) {
    int currP = 0;  

    for (int i = 0; i < cooksRank.size(); i++) {
        int R = cooksRank[i];
        int j = 1;  
        int timeTaken = 0;

        // Each cook keeps making pratas until time exceeds mid
        while (true) {
            if (timeTaken + j * R <= mid) {
                ++currP;  
                timeTaken += j * R;  
                ++j;  
            } else {
                break;
            }
        }

        if (currP >= nP) {
            return true;  // Enough pratas cooked
        }
    }

    return false;
}

// Function to find minimum time to complete nP pratas
int minTimeToCompleteOrder(const vector<int>& cooksRank, int nP) {
    int start = 0;
    int highestRank = *max_element(cooksRank.begin(), cooksRank.end());

    // Max time = slowest cook making all pratas
    int end = highestRank * (nP * (nP + 1) / 2);
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossibleSolution(cooksRank, nP, mid)) {
            ans = mid;
            end = mid - 1;  // Try smaller time
        } else {
            start = mid + 1;  // Need more time
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int nP, nC;
        cin >> nP >> nC;

        vector<int> cooksRank(nC);
        for (int i = 0; i < nC; i++) {
            cin >> cooksRank[i];
        }

        cout << minTimeToCompleteOrder(cooksRank, nP) << endl;
    }

    return 0;
}
