#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height) {
    int max = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
        int h = ((height[l]>height[r])?height[r]:height[l]);
        int w = r-l;
        max = (h*w>max)?h*w:max;
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return max;
}

int main(){
	vector <int> height;
	for(int i=0; i<10; i++){
		height.push_back(i);
	}
	cout << maxArea(height) << endl;


	return 0;
}