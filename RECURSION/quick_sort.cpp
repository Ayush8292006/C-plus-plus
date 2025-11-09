#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void quickSort(vector<int>&a, int start, int end){
    if(start>=end){
        return;
    }
    int pivot = end;
    int i = start-1;
    int j = start;

    while(j<pivot){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    i++;
    swap(a[i],a[pivot]);
    quickSort(a,start,i-1);
    quickSort(a,i+1,end);
}

int main(){
    vector<int> a{8,4,2,1};


  quickSort(a,0,a.size()-1);
    cout<<"Sorted Array is : ";

    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}