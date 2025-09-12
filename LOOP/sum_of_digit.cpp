#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int sum = 0;

    int r;
   while(n>0){
    r = n%10;
    sum+=r;
    n = n/10;
   }

   cout<<sum;
 
    
}