// 0013 Roman to Integer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class SolutionV1 {
public:
	int romanToInt(string s) {
		unordered_map<char, int> rToIMap;
		insertRomanToInt(rToIMap);
		int n = s.size();
		int result = 0;
		for (int i = 0; i < n; ++i) {
			if (i == n - 1)
				result += rToIMap[s[i]];
			else {
				int j = rToIMap[s[i + 1]] - rToIMap[s[i]];
				if (j > 0) {
					result += j;
					++i;
				}
				else
					result += rToIMap[s[i]];
			}
		}
		return result;
	}

	void insertRomanToInt(unordered_map<char, int>& map) {
		map.insert(make_pair('I', 1));
		map.insert(make_pair('V', 5));
		map.insert(make_pair('X', 10));
		map.insert(make_pair('L', 50));
		map.insert(make_pair('C', 100));
		map.insert(make_pair('D', 500));
		map.insert(make_pair('M', 1000));
	}
};

class Solution {
public:
	int romanToInt(string s) {
		int n = s.size();
		int result = 0;
		for (int i = 0; i < n; ++i) {
			if (i == n - 1)
				result += romanCharToInt(s[i]);
			else {
				int j = romanCharToInt(s[i + 1]) - romanCharToInt(s[i]);
				if (j > 0) {
					result += j;
					++i;
				}
				else
					result += romanCharToInt(s[i]);
			}
		}
		return result;
	}

	int romanCharToInt(char c) {
		switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
		}
	}
};

int main()
{
	Solution solu;
	string s;

	//test1 return 3
	s = "III";
	cout << solu.romanToInt(s) << ", 3" << endl;
	
	//test2 return 4
	s = "IV";
	cout << solu.romanToInt(s) << ", 4" << endl;
	
	//test3 return 9
	s = "IX";
	cout << solu.romanToInt(s) << ", 9" << endl;

	//test4 return 58
	s = "LVIII";
	cout << solu.romanToInt(s) << ", 58" << endl;
	
	//test5 return 1994
	s = "MCMXCIV";
	cout << solu.romanToInt(s) << ", 1994" << endl;

	//test6 return 2000
	s = "MM";
	cout << solu.romanToInt(s) << ", 2000" << endl;
    return 0;
}

