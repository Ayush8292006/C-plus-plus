#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){

    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=input.size()-1;i>=0;i--){
        int curr = input[i];

        while(s.top()>=curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);


        
    }
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
}