#include<iostream>
using namespace std;

int main(){

    // const int x = 10; // x is constant not change

    // // initialzation can be done but we cant reassign a value
    // // x = 5;

    //  cout<<x<<endl;



    // 2. const with pointers
    int *a = new int;
    *a = 2;
    cout<<*a<<endl;
  
    int b=5;
    a = &b;
    cout<<*a<<endl;
}