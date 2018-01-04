#include <map>
#include <iostream>
#include <vector>
using namespace std;

bool isUnique(string s, int start, int end){
    for(int i=start; i<=end-1; i++){
        if(s[i] == s[end]){
            return false;
        }
    }
    return true;
}

int lengthOfLongestSubstring(string s) {
    int length = s.length();
    if(length <= 1){ return length;}
    int ans = 0;
    for(int start=0; start<length; start++){
        int longest = 1;
        for(int substring=start+1; substring<length; substring++){
            if(isUnique(s, start, substring)){
                longest += 1;
            }else{
                break;
            }
        }
        if(longest > ans){
            ans = longest;
        }
    }
    return ans;
}

//slide window
int lengthOfLongestSubstringQuicker(string s) {
    int length = s.length();
    if(length <= 1){ return length;}
    map<char, int> hashmap;//use hashmap to check if there is a duplicated char
    int ans = 1;
    hashmap.insert(make_pair(s[0],0));
    for(int window=1; window<length; window++){
        map<char,int>::iterator it = hashmap.find(s[window]);
        if( it != hashmap.end()){
            if(hashmap.size() > ans){
                ans = hashmap.size();
            }
            hashmap.clear();
            window = it->second + 1;
            
        }
        hashmap.insert(make_pair(s[window],window));
        
    }
    if(hashmap.size() > ans){
        ans = hashmap.size();
    }
    return ans;
}

int main(){
    string tests[4] = {"abcabcbb", "bbbbbbb", "pwwkew", "abcabcdb"};
    int anses[4] = {3,1,3,4};
    for(int i=0; i<4; i++){
        if(lengthOfLongestSubstring(tests[i]) == anses[i]){
            cout << "pass test " << i << "!" << endl;
        }else{
            cout << "fail test " << i << "!" << endl;
        }
    }

    for(int i=0; i<4; i++){
        if(lengthOfLongestSubstringQuicker(tests[i]) == anses[i]){
            cout << "pass test " << i << "!" << endl;
        }else{
            cout << "fail test " << i << "!" << endl;
        }
    }
    return 0;
}