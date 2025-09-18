
#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+ (e-s)/2;

    while(s<=e){
        if(s==e){
            return s;
        }

        if(mid%2 == 0){
            if(arr[mid] == arr[mid+1]){
                s = mid+2;
            }
            else{
                 e= mid;
            }
        }
        else{
            if(arr[mid] == arr[mid-1]){
                s = mid+1;
            }
            else{
                e = mid -1;
            }
        }
        mid = s+ (e-s)/2;
    }
    return s;
}


int main(){
    vector<int> v{1,1,2,2,3,3,4,4,3,600,600,4,4};

    int ans = solve(v);

    cout<<" index is "<<ans<<endl;
    cout<<" value is "<<v[ans]<<endl;
    return 0;
}