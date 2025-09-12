#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int rev = 0;

    int r =0;
   while(n>0){
    rev = rev*10;
    r = n%10;
    rev+=r;
    n = n/10;
   }

   cout<<rev;
 
    
}