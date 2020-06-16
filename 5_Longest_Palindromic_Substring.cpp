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

/* Solution:
1. **A palindrome is a string which reads the same in both directions.**
2. For example, SS = "aba" is a palindrome, SS = "abc" is not.
算法见笔记，有空再整理*/

#include <iostream>
#include <string>
using namespace std;
class SolutionV1 {
	//非常慢
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
		int pL = 0;
		static int result[2]; //result[0]返回长度， result[1]起始位置
		result[0] = 0;
		result[1] = 0;
		if (i <= n - 1){
			minI = i;
			maxI = i;
		}
		else {
			minI = i - n;
			maxI = i - n + 1;
			if (s[minI] != s[maxI])
				return result;
		}
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
	string s;
	//test1 return "bab" or "aba"
	s = "babad";

	//test2 return "bb"
	//s = "cbbd";

	//test3 return "abcba" 
	//s = "lmabcbac";

	//test4 return ""
	s = "";

	Solution solu;
	cout << solu.longestPalindrome(s) << endl;

	string a = "";
	cout << a.substr(0,0) << endl;
	a = a + 'a' + 'b';
	cout << a << endl;
	
	system("pause");
    return 0;
}

