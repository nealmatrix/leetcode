//1 Two Sum
/* Description:
Given an array of integers, return indices of the two numbers such that 
they add up to a specific target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
*/

/* Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/

/* Solution:
brute force可以做，但是用hash table可以进一步提高效率
可以用one-pass hash table，即加入一个数的时候先检测是否有对应的数已经在hash table中了。
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		
		//Solution 1: brute force
		/*vector<int>::iterator p1, p2;
		vector<int> result;
		for (p1 = nums.begin(); p1 < nums.end() - 1; ++p1) {
			int target2 = target - *p1;
			p2 = find(p1 + 1, nums.end(), target2);
			if(p2!=nums.end())
			{
				break;
			}
		}
		result.push_back(p1 - nums.begin());
		result.push_back(p2 - nums.begin());
		return result;
		*/

		//Solution 2: one-pass hash table
		unordered_map<int, int> map; //int,int -> a[i], i
		vector<int> result;
		for (vector<int>::iterator p = nums.begin(); p != nums.end(); ++p) {
			int target2 = target - *p;
			unordered_map<int, int>::iterator q = map.find(target2);
			if (q != map.end()) {
				result.push_back(q->second);
				result.push_back(p - nums.begin());
				break;
			}
			map.insert(make_pair(*p, p - nums.begin()));
		}
		return result;
	}
};

int main()
{
	int a[4] = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> nums(a, a + 4);
	vector<int>::iterator p;
	vector<int> result;
	Solution solution;

	result= solution.twoSum(nums, target);
	ostream_iterator<int> oit(cout, ",");
	copy(result.begin(), result.end(), oit);
	
	//find如果找不到，则会返回nums.end()
	/*p=find(nums.begin(), nums.end(), 10); 
	cout << p - nums.begin()<<endl;
	*/
    
	//copy用于输出,其中oit的<int>和vector的<int>一致
	/*sort(nums.begin(), nums.end());
	ostream_iterator<int> oit(cout, ".");
	copy(nums.begin(), nums.end(), oit);
	*/

    return 0;
}

