//5 Longest Palindromic Substring

/* Description:
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.*/

/* Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"*/

/* Solution 1 center expand:
1. A palindrome is a string which reads the same in both directions.
2. 以字母和字母与字母之间的间隙为中心，一共2n-1个中心
3. 以每个中心，向左右扩展，检测每个中心的最大回文半径
4. 复杂度为中心个数O(n)*检测半径O(n) = O(n^2)*/

/* Solution 2 Manacher's algorithm
1. non-trivial algorithm, 复杂度为O(n)
因算法较为复杂，另外写一个md文件*/

#include <iostream>
#include <string>
using namespace std;
class Solution_2 {
	//非常慢,因为centerExpand是在进行string的赋值运算，会很慢
	//Solution中centerExpand只是在进行数值运算会快很多
public:
	string longestPalindrome(string s) {
		int n = s.size();
		string pS = "";
		for (int i = 0; i <= 2 * n - 2; i++) {
			string temp = centerExpand(s, i);
			if (temp.size() > pS.size()) {
				pS = temp;
			}
		}
		return pS;
	}
	string centerExpand(string s, int i) {
		// i 是center的序号，0 - (n-1)是字母为center, n - (2n-2)是字母和字母之间的空隙为center0
		int n = s.size();
		int minI, maxI;
		string pS = "";
		if (i <= n - 1) {
			minI = i;
			maxI = i;
			pS = s[i];
		}
		else {
			minI = i - n;
			maxI = i - n + 1;
			if (s[minI] != s[maxI])
				return pS;
			else
				pS = pS + s[minI] + s[maxI];
		}
		int j = 1;
		while (minI - j >= 0 && maxI + j <= n - 1) {
			if (s[minI - j] == s[maxI + j]) {
				pS = s[minI - j] + pS + s[maxI + j];
				j++;
			}
			else
				break;
		}
		return pS;
	}
};
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		int result[2] = {0,0};
		for (int i = 0; i <= 2*n - 2; i++) {
			int* temp = centerExpand(s, i);
			if (temp[0] > result[0]) {
				for (int j = 0; j < 2; j++)
					result[j] = temp[j];
			}
		}
		return s.substr(result[1], result[0]);
	}
	int* centerExpand(string s, int i) {
	// i 是center的序号，0 - (n-1)是字母为center, n - (2n-2)是字母和字母之间的空隙为center0
		int n = s.size();
		int minI, maxI;
		static int result[2]; //result[0]返回长度， result[1]起始位置
		result[0] = 0;
		result[1] = 0;
		//center为字母，以字母序号为起始
		if (i <= n - 1){
			minI = i;
			maxI = i;
		}
		//center为间隙，以间隙左右两边的字母为开始
		else {
			minI = i - n;
			maxI = i - n + 1;
			if (s[minI] != s[maxI])
				return result;
		}
		//以center为中心向左右两边扩展
		int j = 1;
		while (minI - j >= 0 && maxI + j <= n - 1) {
			if (s[minI - j] == s[maxI + j]) {
				j++;
			}
			else
				break;
		}
		j--;
		result[1] = minI - j;
		result[0] = maxI - minI + 2 * j + 1;
		return result;
	}
};

int main()
{
	//input
	string s;
	Solution sol;

	cout << "Expected: bab or aba " << endl;
	s = "babad";
	cout << sol.longestPalindrome(s) << endl;

	cout << "Expected: bb " << endl;
	s = "cbbd";
	cout << sol.longestPalindrome(s) << endl;

	cout << "Expected: abcba " << endl;
	s = "lmabcbac";
	cout << sol.longestPalindrome(s) << endl;

	cout << "Expected: \"\"" << endl;
	s = "";
	cout << sol.longestPalindrome(s) << endl;
	
	system("pause");
    return 0;
}

