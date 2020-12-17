//14 Longest Common Prefix
/* Description：
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".*/

/*Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int numV = strs.size();
		string result = "";
		if (numV == 0)
			return result;
		int minS = strs[0].size();
		//确定strs的最小长度
		for (int i = 1; i < numV; ++i) {
			int size_i = strs[i].size();
			if (size_i < minS)
				minS = strs[i].size();
		}
		int j = 0;
		//在最小长度范围内，比较每个字符
		for (; j < minS; ++j) {
			char c = strs[0][j];
			for (int i = 1; i < numV; ++i) {
				if (c != strs[i][j]) {
					result = strs[0].substr(0, j);
					return result;
				}					
			}
		}
		result = strs[0].substr(0, j);
		return result;
	}
};


int main()
{
	Solution solu;
	vector<string> strs;

	cout << "Expect: f1" << endl;
	strs = { "flower", "flow", "flight" };
	cout << "Output: " << solu.longestCommonPrefix(strs) << endl;
	
	cout << "Expect: \"\"" << endl;
	strs = { "dog", "racecar", "car" };
	cout << "Output: " << solu.longestCommonPrefix(strs) << endl;

	cout << "Expect: \"\"" << endl;
	strs = { "" };
	cout << "Output: " << solu.longestCommonPrefix(strs) << endl;
	
	cout << "Expect: a" << endl;
	strs = { "aa","a" };
	cout << "Output: " << solu.longestCommonPrefix(strs) << endl;

    system("pause");
	return 0;
}

