
#include<iostream>

using namespace std;

bool checkPalindrome(string&s, int start, int end){
    // base
    if(start >= end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }

    return checkPalindrome(s,start+1,end-1);
}

int main(){
    string s;
    cin>>s;

 int ans = checkPalindrome(s,0,s.size()-1);
 if(ans == false){
    cout<<"Not a Palindrome";
 }
 else{
    cout<<"Is a Palindrome";
 }
}