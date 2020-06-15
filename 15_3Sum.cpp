// 0015 3Sum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <vector>
#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {


		vector<vector<int>> result;
		return result;

	}
};

template <class T>
void print(T first, T last) {
	for (; first != last; ++first) {
		cout << * first << " ";
	}
	cout << endl;
}

int main()
{


	int n_array[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> nums(n_array, n_array + 6);
	
	//sort
	sort(nums.begin(), nums.end());
	print(nums.begin(), nums.end());
	
	//set
	set<int> nums_set;
	nums_set.insert(nums.begin(), nums.end());
	print(nums_set.begin(), nums_set.end());

	Solution s;
	vector<vector<int>> result = s.threeSum(nums);

	for (unsigned int i = 0; i < result.size(); ++i) {
		for (unsigned int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	//ostream_iterator
	system("pause");
    
}

