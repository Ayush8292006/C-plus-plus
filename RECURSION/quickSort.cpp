#include<iostream>
using namespace std;

int partion(int arr[], int s, int e){
    // choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];
    //find right position for pivot element
    int count =0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivotElement){
            count++;
        }
    }
    // place pivot element at right position
    int rightIndex = s + count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex = rightIndex;    

    // left and right part sort
    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;

}

void quickSort(int arr[], int s, int e){
    //base
    if(s>=e)
    return;


    //partion logic
    int p = partion(arr,s,e);

    //left sort
    quickSort(arr,s,p-1);

    //right sort
    quickSort(arr,p+1,e);
}

int main(){
    int arr[]= {1,2,4,3,5,7,34,23,4,95,9};
    int n = 11;
    int s =0;
    int e = n-1;
    quickSort(arr,s,e);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}