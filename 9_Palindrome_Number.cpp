// 0009 Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Solution {
public:
	bool isPalindromeV1(int x) {
		string s = to_string(x);
		int n = s.size();
		int minI, maxI;
		if (n % 2 == 0) {
			minI = n / 2 - 1;
			maxI = n / 2;
		}
		else {
			minI = maxI = (n - 1) / 2;
		}
		int j = 0;
		while (minI - j >= 0 && maxI + j <= n - 1) {
			if (s[minI - j] != s[maxI + j])
				return false;
			j++;
		}
		return true;
	}

	bool isPalindrome(int x) {
		std::string orig = std::to_string(x);
		// Make a copy of it
		std::string rev(orig);
		// which is the same as
		// std::string rev = orig;

		// Reverse it
		std::reverse(rev.begin(), rev.end());

		return (orig == rev);
	}
};

int main()
{
	Solution solu;
	int x;
	//test1 return true
	x = 121;
	cout << boolalpha << solu.isPalindrome(x) << ", true" << endl;

	//test2 return false
	x = -121;
	cout << solu.isPalindrome(x) << ", false" << endl;
	
	//test3 return false
	x = 10;
	cout << solu.isPalindrome(x) << ", false" << endl;
    return 0;
}

