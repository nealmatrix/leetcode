// 0010 Regular Expression Matching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size();
		int m = p.size();
		//构建（n+1）*（m+1）的二位数组
		bool** dp = new bool*[n + 1];
		for (int i = 0; i < n+1; i++)
			dp[i] = new bool[m + 1];

		//给dp[0][0], dp[i][0]. dp[0][j]赋值
		dp[0][0] = true;
		for (int i = 1; i < n + 1; i++)
			dp[i][0] = false;
		for (int j = 1; j < m + 1; j++) {
			if (!dp[0][j-1] || j == m || p[j] != '*')
				dp[0][j] = false;
			else {
				j++;
				dp[0][j] = true;
			}
		}
		char slc, plc; //slc: s last character, plc: pattern last character
		for (int i = 1; i< n + 1; i++)
			for (int j = 1; j < m + 1; j++) {
				slc = s[i - 1];
				plc = p[j - 1];
				if (plc == slc || plc == '.')
					dp[i][j] = dp[i - 1][j - 1];
				else if (plc == '*') {
					if (p[j - 2] == slc || p[j - 2] == '.')
						dp[i][j] = dp[i - 1][j] || dp[i][j-2];
					else
						dp[i][j] = dp[i][j - 2];
				}
				else
					// plc是字母且不与slc相同
					dp[i][j] = false;
			}
		bool result = dp[n][m];
		for (int i = 0; i < n+1; i++)
			delete dp[i];
		delete dp;
		return result;
	}
};


int main()
{
	string s, p;
	Solution solu;

	//test1 return false
	s = "aa";
	p = "a";
	cout << boolalpha << solu.isMatch(s, p) << "," << false << endl;

	//test2 return true
	s = "aa";
	p = "a*";
	cout << boolalpha << solu.isMatch(s, p) << "," << true << endl;

	//test3 return true
	s = "ab";
	p = ".*";
	cout << boolalpha << solu.isMatch(s, p) << "," << true << endl;

	//test4 return true
	s = "aab";
	p = "c*a*b";
	cout << boolalpha << solu.isMatch(s, p) << "," << true << endl;

	//test5 return false
	s = "mississippi";
	p = "mis*is*p*.";
	cout << boolalpha << solu.isMatch(s, p) << "," << false << endl;

	//test6 return true
	s = "aaa";
	p = "ab*a*";
	cout << boolalpha << solu.isMatch(s, p) << "," << true << endl;
	
    return 0;
}

