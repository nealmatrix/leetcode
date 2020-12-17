//11 Container With Most Water

/* Description:
Given n non-negative integers a1, a2, ..., an , where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is 
at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.*/

/*Note: You may not slant the container and n is at least 2.*/

/* Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49*/

/* Solution:
Greedy algorithm, 
1. 左右边分别从a1和an起，向中间移动，每次记录面积
2. 每次移动较短的边，向较大的边移动
复杂度为O(n) */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxA = 0;
		int temp;
		vector<int>::iterator i = height.begin();
		vector<int>::iterator j = height.end() - 1;
		while (i != j) {
			temp = min(*i, *j)*(j - i);
			if (temp > maxA)
				maxA = temp;
			if (*i > *j)
				--j;
			else
				++i;
		}
		return maxA;
	}
};

//print vector
template<class T>
void printVector(vector<T>& v) {
	typename vector<T>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

int main()
{
	
	Solution solu;
	cout << "Expect: 49" << endl;
	vector<int> height({ 1,8,6,2,5,4,8,3,7 });
	printVector(height);
	cout << "Output: " << solu.maxArea(height) << endl;

	system("pause");
    return 0;
}



