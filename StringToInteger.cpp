#include <iostream>
using namespace std;

int myAtoi(string str){
	int ans = 0;
	int sign = 1;
	int i = 0;
	while(str[i] == ' '){
		i++;
	}

	if(str[i] == '-' ){
		sign = -1;
		i++;
		if(str[i] == '+'){
			return 0;
		}
	}else if(str[i] == '+'){
		sign = 1;
		i++;
		if(str[i] == '-'){
			return 0;
		}
	}

	cout << sign << endl;
	while('0' <= str[i] && str[i] <= '9' && i<str.length()){
		ans *= 10;
		ans += (str[i] - '0');

		cout << "current answer: " << ans << endl;
		i++;
	}

	if(i < str.length()-1){
		return 0;
	}
	return ans * sign;
}

int main(){
	string str[]={"123", "-133", "+2341", "abcs", "12asb", "+-123"};
	for(int i=0; i<6; i++){
		cout << "answer " << i << ": ";
		cout << myAtoi(str[i]) << endl;
	}
	return 0;
}