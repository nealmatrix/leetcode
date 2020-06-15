// 0011 Container With Most Water.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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

template<class T>
void printvector(vector<T>& v) {
	//print vector
	vector<T>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

int main()
{
	
	Solution solu;
	//test1 return 49
	int a[] = { 1,8,6,2,5,4,8,3,7 };
	vector<int> height(a, a + 9);
	printvector(height);
	cout << solu.maxArea(height) << endl;


    return 0;
}



