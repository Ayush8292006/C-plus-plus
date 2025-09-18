



#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid){
    long long int wwodCollected = 0;
    for( long long int i = 0; i<trees.size();i++){
        if(trees[i]>mid){
            wwodCollected += trees[i]-mid;
        }
        
    }
    return wwodCollected >= m;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m) {
    long long int start = 0, end , ans = -1;
    
    end = *max_element(trees.begin(),trees.end());

    while(start<=end){
        long long mid = start +(end-start)/2;
        if(isPossibleSolution(trees,m,mid)){
            ans = mid;
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        
    }
    return ans;
}

int main() {
    long long int n, m;
    cin>>n>>m;

    vector<long long int> trees;
       for (long long int i = 0; i < n; i++) {   // FIX: use for-loop instead of while(n--)
        long long int height;
        cin >> height;
        trees.push_back(height);
    }
    cout <<"ans is "<< maxSawBladeHeight(trees, m);
}
