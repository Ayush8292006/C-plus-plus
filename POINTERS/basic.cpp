#include<iostream>
using namespace std;

int main(){
 
    
//     int a=5;
//    cout<<&a<<endl;

//     // pointer create 

//     int* ptr = &a;
//     cout<<ptr<<endl;
//     cout<<&ptr<<endl;

//     cout<<*ptr<<endl;


// int a= 5;
// int* ptr = &a;

// cout<<sizeof(ptr)<<endl;
// char ch= 5;
// char* c = &ch;

// cout<<sizeof(c)<<endl;
// double dtr= 5;
// double* d = &dtr;

// cout<<sizeof(d)<<endl;


// copy a pointer

// int a=5;
// int* p = &a;

// int* second = p;

// cout<<p<<endl;
// cout<<second<<endl;




int a= 10;
int*p = &a;
int* q= p;
int*r = q;

cout<<a<<endl;
cout<<&a<<endl;
cout<<p<<endl;
cout<<&p<<endl;
cout<<*p<<endl;
cout<<q<<endl;
cout<<&q<<endl;
cout<<*q<<endl;
cout<<r<<endl;
cout<<a<<endl;
cout<<&r<<endl;
cout<<*r<<endl;
cout<<(*p + *q + *r)<<endl;
cout<<(*p)*2 + (*r)*3<<endl;

}