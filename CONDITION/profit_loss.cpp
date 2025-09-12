#include<iostream>
using namespace std;

int main(){
   int sp,cp;

   cin>>sp>>cp;

   if(sp>cp){
    cout<<"profit";
   }

   else if (sp==cp){
    cout<<"no profit no loss";
   }
   else{
    cout<<"loss";
   }
    
}