#include<iostream>
#include<vector>
using namespace std;

// int countInversion(vector<int> &v){
//     int count = 0;
//     for(int i =0; i<v.size();i++){
//         for(int j = i+1; j<v.size();j++){
//             count = v[i]>v[j]?count +1:count;
//         }
//     }
//     return count;
// }

long long merge(vector<int>& v, vector<int>& temp, int start, int mid, int end) {
    long long invCount = 0;
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
            invCount += (mid - i + 1);    
        }
    }

    while (i <= mid) 
        temp[k++] = v[i++];
    while (j <= end) 
        temp[k++] = v[j++];

    for (int p = start; p <= end; p++) {
        v[p] = temp[p];
    }

    return invCount;
}

long long mergeSort(vector<int>& v, vector<int>& temp, int start, int end) {
    long long invCount = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;

        invCount += mergeSort(v, temp, start, mid);
        invCount += mergeSort(v, temp, mid + 1, end);

        invCount += merge(v, temp, start, mid, end);
    }
    return invCount;
}

long long countInversion(vector<int>& v) {
    vector<int> temp(v.size());
    return mergeSort(v, temp, 0, v.size() - 1);
}

int main(){
    vector<int> v{8,4,2,1};

    int ans = countInversion(v);
    cout<<ans<<endl;
}