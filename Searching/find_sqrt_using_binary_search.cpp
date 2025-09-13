#include<iostream>
using namespace std;

int findsqrt(int n){
    int target = n;
    int s = 0;
    int e = n;
    int mid = s+ (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(mid*mid == target){
            return mid;
        }
        if(mid*mid > target){
            e = mid-1;
        }
        else{
            ans = mid;
            s = mid+1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int main(){
    int n ; 
    cin>>n;
     int ans = findsqrt(n);

     cout<<ans<<endl;

     int prescision;
     cout<<"Enter no. of floating disgit in precision"<<endl;
     cin>> prescision;

     double step =  0.1;
     double finalAns = ans;
     for(int i = 0; i<prescision; i++){
        for(double j =finalAns; j*j<=n; j= j+step){
            finalAns = j;
        }
        step = step/10;
     }
     cout<<finalAns;

     return 0;

}