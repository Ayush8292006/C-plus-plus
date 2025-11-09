#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Recursive helper to find max profit
    void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
        // Base case
        if (i == prices.size()) return;

        // Update minimum price seen so far
        if (prices[i] < minPrice)
            minPrice = prices[i];

        // Calculate today's profit if sold today
        int todayProfit = prices[i] - minPrice;

        // Update maxProfit if better
        if (todayProfit > maxProfit)
            maxProfit = todayProfit;

        // Recursive call for next day
        maxProfitFinder(prices, i + 1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0; // not INT_MIN (profit can be 0)

        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
