#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    bool flag = true;
   for(int i =2;i<= n-1;i++){

    if(n==1) cout<<"neither prime nor composite<<endl;"

    if(n%i==0){
        flag = false;
        cout<<"composite"<<endl;
        break;
    }
    if(flag == true ) cout<<" prime"<<endl;
    break;
        
   }
 
    
}