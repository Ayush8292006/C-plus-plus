


// return present or not and index

// #include <iostream>
// using namespace std;

// int checkkey(string& str, int i, int& n, char& key) {
//     if (i >= n) {
//         return -1;   // Base case: not found
//     }
//     if (str[i] == key) {
//         return i;    // Found the key
//     }
//     return checkkey(str, i + 1, n, key); // Recursive call
// }

// int main() {
//     string str = "Ayushsrivastav";
//     int n = str.length();
//     char key = 'a';
//     int i = 0;

//     int ans = checkkey(str, i, n, key);
//     cout << ans << endl;   // Output -> 6

//     return 0;
// }


// all occurence

// #include <iostream>
// using namespace std;

// void checkkey(string& str, int i, int& n, char& key) {
//     if (i >= n) {
//         return ;   // Base case: not found
//     }
//     if (str[i] == key) {
//         cout<< i<<" ";    // Found the key
//     }
//     return checkkey(str, i + 1, n, key, ans); // Recursive call
// }

// int main() {
//     string str = "Ayushsrivastav";
//     int n = str.length();
//     char key = 'a';
//     int i = 0;

//      checkkey(str, i, n, key);
  

//     return 0;
// }


// count


#include <iostream>
using namespace std;

void checkkey(string& str, int i, int& n, char& key, int& count) {
    if (i >= n) {
        return;   // Base case
    }
    if (str[i] == key) {
        count++;  // Increment count if match found
    }
    checkkey(str, i + 1, n, key, count); // Recursive call
}

int main() {
    string str = "Ayushsrivastav";
    int n = str.length();
    int count = 0;
    char key = 'a';
    int i = 0;

    checkkey(str, i, n, key, count);

    cout << "Character '" << key << "' occurs " << count << " times." << endl;

    return 0;
}


// ans store

// #include <iostream>
// #include<vector>
// using namespace std;

// void checkkey(string& str, int i, int& n, char& key, vector<int>& ans) {
//     if (i >= n) {
//         return ;   // Base case: not found
//     }
//     if (str[i] == key) {
//       ans.push_back(i);
//     }
//     return checkkey(str, i + 1, n, key, ans); // Recursive call
// }

// int main() {
//     string str = "Ayushsrivastav";
//     int n = str.length();
//     vector<int> ans;
//     char key = 'a';
//     int i = 0;

//      checkkey(str, i, n, key, ans);
//      for(auto val: ans){
//         cout<<val<<" ";
//      }
//      cout<<endl;
  

//     return 0;
// }




 