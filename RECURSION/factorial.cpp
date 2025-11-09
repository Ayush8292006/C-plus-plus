#include<iostream>
using namespace std;

int factorial(int n){

    // bace case 
    if(n==1) {
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
     int n;
     cin>>n;

     int ans = factorial(n);
     cout<<ans<<endl;
     return 0;
}