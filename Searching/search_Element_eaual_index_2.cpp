#include<iostream>
#include<vector>
using namespace std;

vector<int> search(vector<int> &arr){
    int n = arr.size();
    vector<int> v;

    for(int i = 0; i < n; i++){
        if(arr[i] == i + 1){
            v.push_back(arr[i]);
        }
    }
    return v;
}

int main(){
    vector<int> arr = {15, 2, 45, 4, 7};
    
    vector<int> ans = search(arr);

    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
