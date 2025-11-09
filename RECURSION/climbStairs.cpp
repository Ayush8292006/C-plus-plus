#include<iostream>
using namespace std;

int climbStairs(int n){
    // base case
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 1;
    }
    return climbStairs(n-1) + climbStairs(n-2);
}

int main(){
    int n;
    cin >> n;
    int ans = climbStairs(n);
    cout<<ans<<endl;

 
   

    return 0;
}



