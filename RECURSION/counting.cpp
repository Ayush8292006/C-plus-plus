#include<iostream>
using namespace std;

int counting(int n){

    // bace case 
    if(n==0) {
        return 0;
    }
    cout<<n<<endl;

     counting(n-1);
}

int main(){
     int n;
     cin>>n;

     counting(n);
 
   
     return 0;
}