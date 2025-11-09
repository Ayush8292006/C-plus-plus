#include<iostream>
using namespace std;

int fib(int n){
    // base case
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms:" << endl;
    for(int i = 1; i <= n; i++){
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}
