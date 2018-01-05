#include <map>
#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    string ans;
    int len = s.length();
    int max = 0;
    int startIndex = 0;
    
    if(len == 1){
        return s;
    }
    bool Plength[len][len];
    // initialize
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            Plength[i][j] = false;
        }
    }

    for(int i=0; i<len; i++){
        for(int j=0; j<=i; j++){
            //check in bound && s[i]==s[j] && (base case or DP function)
            if(s[i]==s[j] && (i-j<=1 || (Plength[i-1][j+1] && i>1 && j<len-1))){
                Plength[i][j] = true;
                if(i-j+1>max){
                    max = i-j+1;
                    startIndex = j;
                }
            }
        }
    }
    for(int i=0; i<len; i++){
        if(i==0){
            cout << '\t';
            for(int j=0; j<len; j++){
                cout << s[j] << '\t';
            }
            cout << endl;
        }
        cout << s[i] << '\t';
        
        for(int j=0; j<len; j++){
            cout << Plength[i][j] << '\t';
        }
        cout << endl;
    }
    cout << startIndex << " " << max << endl;
    ans = s.substr(startIndex, max);

    return ans;
}

int main(){
    string s = "bb";
    cout << longestPalindrome(s) << endl;
    cout << longestPalindrome("abcba") << endl;
    cout << longestPalindrome("abcda") << endl;
    return 0;
}