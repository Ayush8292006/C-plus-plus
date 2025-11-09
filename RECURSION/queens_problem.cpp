#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {

    // check upper diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) return false;
    }

    // check left
    for(int j = col; j >= 0; j--) {
        if(board[row][j] == 1) return false;
    }

    // check lower diagonal
    for(int i = row, j = col; i < n && j >= 0; i++, j--) {
        if(board[i][j] == 1) return false;
    }

    return true;
}

void printBoard(vector<vector<int>> &board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1) cout << "Q ";
            else cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<int>> &board , int col, int n) {

    // base case
    if(col >= n){
        printBoard(board,n);
        return;
    }

    // try placing queen in each row
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;        // place
            solve(board, col + 1, n);   // recur
            board[row][col] = 0;        // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(board, 0, n);

    return 0;
}
