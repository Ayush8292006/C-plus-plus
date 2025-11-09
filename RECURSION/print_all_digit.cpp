#include <iostream>
using namespace std;

void printDigit(int n) {
    if (n == 0) {
        return;  // Base case
    }
    int digit = n % 10;

    // cout << digit << " ";   // 7 4 6

    int newValue = n / 10;

    printDigit(newValue);   // Recursive call first
    cout << digit << " ";   // 6 4 7
}

int main() {
    int n = 647;
    if(n==0){
        cout<<n<<endl;
    }
    printDigit(n);
    return 0;
}
 