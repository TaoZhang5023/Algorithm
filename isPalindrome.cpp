#include <iostream>
using namespace std;

bool isPalindrome(int x) {
	if(x == 0){
		return true;
	}

    if(x<0 || (x % 10 == 0)){
    	return false;
    }

    int revertedNum = 0;

    while (x > revertedNum){
    	revertedNum = revertedNum * 10 + x%10;
    	x/=10;
    }

    return x == revertedNum || x == revertedNum/10;
}

int main(){
	int test[8] = {-123, 1234, 23432, 12344321, 123210, 2737800, 153333351, 0};
	bool ans[8] = {false, false, true, true, false, false, true, true};
	for(int i=0; i<8; i++){
		cout << "tetsing input: " << test[i] << endl;
		cout << "result: " << isPalindrome(test[i]) << endl;
		cout << "ans: " << ans[i] << endl;
	}
	bool a = 2737800 % 10 == 0;
	cout << a << endl;
	return 0;
}