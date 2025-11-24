#include<iostream>
using namespace std;

int x =2; // global variable

void fun(){
    int x = 70;
    cout<<x<<endl;
    ::x=90;
    cout<<::x<<endl;
}


int main(){

    x = 20; // global x
    int x =40; // local to main() function
  
    cout<<x<<endl;
      cout<<::x<<endl; // access global variable

      // more prefernce of local variable, most local print hoga
      {
        int x =50;
        cout<<x<<endl;
      }

      fun();
}