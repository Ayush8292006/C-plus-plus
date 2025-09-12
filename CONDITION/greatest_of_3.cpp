#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enet a : ";
    cin>>a;
    int b;
    cout<<"Enet b : ";
    cin>>b;
    int c;
    cout<<"Enet c : ";
    cin>>c;

    if(a> b && a>c){
        cout<<a<<"is greatest";
    }
     else if(b> a && b>c){
        cout<<b<<"is greatest";
    }
    else{
        cout<<c<<"is greatest";
    }
    
   
 
    
}