#include<iostream>
using namespace std;

 // Better approach

void sortColor(int *a, int n){

    int l = 0, h = n-1, m =0;

    while(m<=h){
        if(a[m] == 0){
            swap(a[l],a[m]);
            l++,m++;
        }
        else if(a[m] == 1){
            m++;
        }
        else{
            swap(a[m],a[h]);
            h--;
        }
    }

}

// Alternative


// void sortColor(int *a, int n){
//     int zro,one,two;
//    int  zero=one=two=0;

//     for(int i =0;i<n; i++){
//         if(a[i]==0) zero++;
//         else if(a[i] == 1) one++;
//         else two++;
//     }
//     int i =0;
//     while(zero--){
//         a[i] = 0;
//         i++;
//     }
//       while(one--){
//         a[i] = 1;
//         i++;
//     }
//       while(two--){
//         a[i] = 2;
//         i++;
        
//     }
// }


int main(){
    int a[] = {1,1,0,2,1,0,2,2,1};
    int n = sizeof(a)/sizeof(int);

   sortColor(a,n);

    for(int i = 0; i<n ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}