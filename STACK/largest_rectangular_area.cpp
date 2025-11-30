#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // previous smaller index
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(arr.size());

        for(int i = 0; i < arr.size(); i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // next smaller index
    vector<int> nextSmaller(vector<int>& arr) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(arr.size());

        for(int i = arr.size() - 1; i >= 0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;

        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int height = heights[i];

            // Use n as boundary if no next smaller
            if(next[i] == -1) next[i] = n;

            int width = next[i] - prev[i] - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    Solution sol;
    cout << "Largest Rectangle Area = " 
         << sol.largestRectangleArea(heights) 
         << endl;

    return 0;
}
