

// Leetcode - 658

#include<iostream>
#include<vector>
using namespace std;

    vector<int> findClosest(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int l = 0; 
        int h = arr.size()-1;
        while(h-l>=k){
            if(x-arr[l] > arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }
        for(int i = l; i<=h; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }

int main(){
    vector<int> arr{1,2,3,4,5};
    int k = 4;
    int x = 3;

   vector<int> ans = findClosest(arr, k, x);
    cout << "Closest " << k << " elements to " << x << " are: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;


}