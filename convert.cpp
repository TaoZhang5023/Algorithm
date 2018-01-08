#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    if(s.length()==1 || numRows==1){
    	return s;
    }
    string ans;
    int charForOne = 2*numRows-2;

	// scan the zigzag pattern line by line
	// there is numRows line, start from the first line
	cout << s.length() << endl;
	for(int j=0; j< numRows; j++ ){ 
		int offset1 = j;
		int offset2 = charForOne-j;
		
		for(int i=0; i*charForOne+offset1 < s.length(); i++){
			ans += s[i*charForOne+offset1];
			if(1 <= j && j <numRows-1 && i*charForOne+offset2 < s.length()){
				ans += s[i*charForOne+offset2];
			}
		}
	}
    return ans;
}

int main(){
//test cases
	string s[] = {
		"PAYPALISHIRING",
		"A",
		"AB"
	};
	int numRows[] = {
		3,
		1,
		1
	};
	
	for( int i=0; i<3; i++){
		cout << convert(s[i],numRows[i]) << endl;
	}
	return 0;
}