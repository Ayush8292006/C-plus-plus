#include <iostream>
#include <algorithm> // for sort
using namespace std;

// first approch  using sort

// int duplicate(int *a, int n){
//     sort(a, a + n); // Correct sort for raw array

//     for(int i = 0; i < n - 1; i++){
//         if(a[i] == a[i + 1]){
//             cout << "Duplicate found: " << a[i] << endl;
//             return a[i];
//         }
//     }

//     cout << "No duplicates found." << endl;
//     return -1;
// }


// second approch  using negative mark

// int duplicate(int *a, int n){
//     int ans = -1;
//     for(int i = 0 ; i<n; i++){
//         int index = abs(a[i]);

//         if(a[index] < 0){
//             ans = index;
//             break;
//         }
//         a[index] *= -1;
//     }
//    cout<< ans;
// }

// Third approach 

int duplicate(int *a, int n) {
    for (int i = 0; i < n; i++) {
        while (a[i] != i) {
            if (a[i] == a[a[i]]) {
                cout << a[i] << endl;
                return a[i];
            }
            swap(a[i], a[a[i]]);
        }
    }
    cout << "No duplicate found" << endl;
    return -1;
}




int main(){
    int a[] = {2, 0, 3, 4, 1, 5, 6, 3, 8};
    int n = sizeof(a) / sizeof(int);

    duplicate(a, n);

    

    return 0;
}
