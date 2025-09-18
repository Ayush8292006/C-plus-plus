#include <iostream>
using namespace std;

int solve(int dividend, int divisor) {
    int start = 0;
    int end = abs(dividend);
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // mid har iteration me calculate karo

        if (abs(mid * divisor) == abs(dividend)) {
            return mid;   // exact answer mil gaya
            break;
        }

        if (abs(mid * divisor) < abs(dividend)) {
            ans = mid;          // possible answer
            start = mid + 1;    // right side check karo
        } else {
            end = mid - 1;      // left side check karo
        }
       
        }
         if((divisor<0 &&  dividend<0) || (divisor>0 && dividend>0)){
            return ans;
    }

    else{
        return -ans;
    }
}

int main() {
    int dividend = -22;
    int divisor = -7;

    int ans = solve(dividend, divisor);

    cout << ans << endl; // output 3 (because 7*3=21 <= 22)
    return 0;
}
