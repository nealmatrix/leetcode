//15 3Sum
/* Description:
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets. */

/* Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
] */

/* Solution:
a,b,c三者没有区别，设置 a <= b <= c.
根据 a + b + c = 0 得到 a <= b <= -a/2 且 a <= 0
注意在程序中j不是b，而是先为b插入set中，然后再为c，和b形成互补值
从左向右，取值为a，将a右边的数组，依次insert到unorder_set中，在
插入之前判断unorder_set中是否有互补值
case1: 如果有互补值，triplet is inserted to result。并且互补值不需要继续插入，
指针指向下一个右边的值，此时注意下一个右边的值一定要比之前的大，否则会有duplicate
case2: 如果没有互补值，直接插入，指针指向下一个右边的值
复杂度为O(n^2)*/

/*Runtime: 
1848 ms, faster than 9.74% of C++ online submissions for 3Sum.
Memory Usage: 
266.2 MB, less than 5.01% of C++ online submissions for 3Sum*/
/*问题可能出在unorder_set find的时候未必是O(1)*/

/* Solution_2:
还是先sort nums，从左向右，为a，确定a后，即确定target，这时候，b和c从右侧的数组两侧向
中间靠拢
case 1： b + c < target， 那么b向右移动
case 2： b + c > target， 那么c向左移动
case 3： b + c = target， 那么b和c一起向中间移动
此时也要注意a，b，c重复的问题，类似于solution中的bigIter函数的功能
复杂度仍为O(n^2)*/

#include <vector>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>
#include <typeinfo>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		//先对nums进行排序，方便得到unique triplets
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		vector<int> triplet;
		for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i){
			unordered_set<int> set;
			vector<int>::iterator j = i + 1;
			//if a >0 或者 b已经到最后 即return
			if (j == nums.end() || *i > 0)
				return result;
			int target = 0 - *i;
			for (; j != nums.end(); ++j){
				vector<int> triplet;
				
				unordered_set<int>::iterator q = set.find(target - *j);
				if (q != set.end()){
					triplet.push_back(*i);
					triplet.push_back(*q);
					triplet.push_back(*j);
					result.push_back(triplet);
					//case 1: 继续插入，此时注意下次插入的值一定要比之前的大
					j = bigIter(nums, j);
				}
				else{
					set.insert(*j);
				}

			}
			i = bigIter(nums, i);
		}
		return result;

	}
	vector<int>::iterator bigIter(vector<int>& nums, vector<int>::iterator j){
		//nums已经排过序
		int b = *j;
		vector<int>::iterator k;
		do{
			k = ++j;
		}
		while (k!=nums.end() && *k == b);
		--j;
		return j;
	}
};

template <class T>
void print(T first, T last) {
	for (; first != last; ++first) {
		cout << * first << " ";
	}
	cout << endl;
}

template <class T>
void print_vector(T first, T last) {
	for (; first != last; ++first) {
		print((*first).begin(), (*first).end());
	}
}

int main()
{
	Solution s;
	//case 1:
	{cout << "case 1:" << endl;
	int n_array[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> nums(n_array, n_array + 6);
	vector<vector<int>> result = s.threeSum(nums);
	print_vector(result.begin(), result.end());}
	
	//case 2:
	{cout << "case 2:" << endl;
	int n_array[5] = {-1, 0, 1, 2, -1};
	vector<int> nums(n_array, n_array + 5);
	vector<vector<int>> result = s.threeSum(nums);
	print_vector(result.begin(), result.end());}
	
	//case 3:
	{cout << "case 3:" << endl;
	int n_array[6] = {-4, -3, 1, 2, 2, 3};
	vector<int> nums(n_array, n_array + 6);
	vector<vector<int>> result = s.threeSum(nums);
	print_vector(result.begin(), result.end());}

	//case 4:
	{cout << "case 4:" << endl;
	int n_array[8] = {-1, -1, 0, 0, 0, 0, 2, 3};
	vector<int> nums(n_array, n_array + 8);
	vector<vector<int>> result = s.threeSum(nums);
	print_vector(result.begin(), result.end());}
	system("pause");
	return 0;
    
}

