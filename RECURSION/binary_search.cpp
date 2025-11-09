#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &v, int s, int e, int key){
    // base case
    if(s > e){
        return -1;
    }
    int mid = s + (e - s) / 2;

    if(v[mid] == key){
        return mid;
    }
    else if(v[mid] < key){
        return binarySearch(v, mid + 1, e, key);
    }
    else{
        return binarySearch(v, s, mid - 1, key);
    }
}

int main(){
    vector<int> v{10,20,30,40,50,70,90,99};
    int n = v.size();
    int target = 99;
    int s = 0;
    int e = n - 1;

    int ans = binarySearch(v, s, e, target);

    cout << "Index of " << target << " is: " << ans << endl;
    return 0;
}
