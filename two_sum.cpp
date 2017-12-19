// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


/*
	O(n) Solution, use hashmap to map the vector.
*/

#include <map>
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> hashmap;
	vector <int> ans;
	for(int i=0;i<nums.size(); i++){
		hashmap.insert(make_pair(nums[i], i));
	}
	for(int i=0; i<nums.size(); i++){
		map<int, int>::iterator it;
		it = hashmap.find(target-nums[i]);
		if( it != hashmap.end()){
			ans.push_back(i);
			ans.push_back(it->second);
			return ans;
		}
	}
	return ans;
}

int main(){
	vector<int> testCase;
	for(int i=1;i<=5000;i++){
		testCase.push_back(i);
	}
	int target = 9999;
	vector<int> ans = twoSum(testCase, target);
	if(ans.size()!=2){
		cout << "No Solution" << endl;
	}else{
		cout << testCase[ans[0]] << "+" << testCase[ans[1]] << "=" << target << endl;
		cout << "answer is: " << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}

