// 0014 Longest Common Prefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
		for (int i = 1; i < numV; ++i) {
			if (strs[i].size() < minS)
				minS = strs[i].size();
		}
		int j = 0;
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
	vector<string> strV;
	int size;
	//test1 return "fl"
	strV.clear();
	string strS1[] = { "flower", "flow", "flight" };
	size = sizeof(strS1) / sizeof(string);
	/*cout << sizeof(strS) << endl;
	cout << sizeof(string) << endl;
	cout << size << endl;*/
	for (int i = 0; i < size; ++i) {
		strV.push_back(strS1[i]);
	}
	cout << solu.longestCommonPrefix(strV) << ", fl" << endl;
	
	//test2 return ""
	strV.clear();
	string strS2[] = { "dog", "racecar", "car" };
	size = sizeof(strS2) / sizeof(string);
	/*cout << sizeof(strS) << endl;
	cout << sizeof(string) << endl;
	cout << size << endl;*/
	for (int i = 0; i < size; ++i) {
		strV.push_back(strS2[i]);
	}
	cout << solu.longestCommonPrefix(strV) << "," << endl;

	//test3 return ""
	strV.clear();
	string strS3[] = { "" };
	size = sizeof(strS3) / sizeof(string);
	/*cout << sizeof(strS) << endl;
	cout << sizeof(string) << endl;
	cout << size << endl;*/
	for (int i = 0; i < size; ++i) {
		strV.push_back(strS3[i]);
	}
	cout << solu.longestCommonPrefix(strV) << "," << endl;
	
	//test4 return "a"
	strV.clear();
	string strS4[] = { "aa","a" };
	size = sizeof(strS4) / sizeof(string);
	/*cout << sizeof(strS) << endl;
	cout << sizeof(string) << endl;
	cout << size << endl;*/
	for (int i = 0; i < size; ++i) {
		strV.push_back(strS4[i]);
	}
	cout << solu.longestCommonPrefix(strV) << ", a" << endl;


	string a = "abc";
	string b;
	b = a + "d";
	cout << a << "," << b << endl;
	a.push_back('d');
	cout << a << "," << b << endl;
    return 0;
}

