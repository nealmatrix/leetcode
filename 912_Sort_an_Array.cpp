// 0912 Sort an Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;



class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		//base case
		int len = nums.size();
		if (len == 0 || len == 1) {
			return nums;
		}

		vector<int> numsSorted;
		
		vector<int> nums1(nums.begin(), nums.begin() + len / 2);
		vector<int> nums2(nums.begin() + len / 2, nums.end());

		vector<int> nums1Sorted = sortArray(nums1);
		vector<int> nums2Sorted = sortArray(nums2);
		numsSorted = mergeArray(nums1Sorted, nums2Sorted);
		return numsSorted;

	}

	vector<int> mergeArray(vector<int>& numsSorted1, vector<int>& numsSorted2) {
		vector<int> numsMerged;
		vector<int>::iterator i = numsSorted1.begin(), j = numsSorted2.begin();
		while (i < numsSorted1.end() && j < numsSorted2.end()) {
			if ( *i <= *j ) {
				numsMerged.push_back(*i);
				i++;
			}
			else {
				numsMerged.push_back(*j);
				j++;
			}
		}
		//当其中一个index(i or j)到end后，将另一个array剩下的数都加入到numsMerged中
		if (i == numsSorted1.end()) {
			for (; j < numsSorted2.end(); j++) {
				numsMerged.push_back(*j);
			}
		}
		else {
			for (; i < numsSorted1.end(); i++) {
				numsMerged.push_back(*i);
			}
		}
		return numsMerged;

	}

};

int main()
{
	int a[6] = { 5, 1, 1, 2, 0, 0 };
	vector<int> v(a, a + 6);
	ostream_iterator<int> oit(cout, ",");
	copy(v.begin(), v.end(), oit);
	cout << endl;

	cout << "after sorted" << endl;
	Solution s;
	vector<int> vSorted = s.sortArray(v);
	copy(vSorted.begin(), vSorted.end(), oit);
	cout << endl;
	return 0;
}