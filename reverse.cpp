#include <iostream>
#include <limits>
using namespace std;

int reverse(int x) {
    int ans = 0;

	for(int i=0; x!=0; i++){
		int temp = ans*10 + x%10;
		if(temp/10 != ans){//check overflow
			return 0;
		}
		ans = temp;
		x /= 10;
	}
	return ans;

}

int main(){
	int tests[] = {0,123,-123,34567,21003,19999987203942241};
	for(int i=0; i<6; i++){
		cout << reverse(tests[i]) << endl;
	}
	return 0;

}
