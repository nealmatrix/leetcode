// 0003 Longest Substring Without Repeating Characters.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstringV1(string s) {
		//用hashtable的思路是正确的，但是不需要删除之前有重复的character。
		//只需要用i和p->second来判断现在新字符重复是在i前还是i后。
		int length = s.size();
		int maxLength = 0;
		int tmpLength = 0;
		unordered_map<char, int> map; //char,int: string中的每个字符和所在的位置
		unordered_map<char, int>::iterator p;
		int i = 0, j = 0;
		for (; i < length; ++i) {
		    p = map.find(s.at(i));
		    if (p != map.end()) {
		        tmpLength = i - j;
		        if (tmpLength > maxLength) maxLength = tmpLength;
		        int repeatIndex = p->second;
		        for (int k = j; k <= repeatIndex; ++k) {
		            map.erase(s.at(k));
				}
				j = repeatIndex + 1;
			}
			map.insert(make_pair(s.at(i), i));
		}
		tmpLength = i - j;
		if (tmpLength > maxLength) maxLength = tmpLength;
		return maxLength;
	}

	int lengthOfLongestSubstringV2(string s) {
		
		int length = s.size();
		int maxLength = 0;
		int tmpLength = 0;
		unordered_map<char, int> map; //char,int: string中的每个字符和所在的位置
		unordered_map<char, int>::iterator p;
		int i = 0, j = 0;
		for (; i < length; ++i) {
			p = map.find(s.at(i));
			if (p != map.end()) {
				if (p->second >= j) j = p->second + 1;
			}
			tmpLength = i - j + 1;
			if (tmpLength > maxLength) maxLength = tmpLength;
			map[s.at(i)]=i;//insert无法覆盖已经存在的key，[]可以覆盖
		}
		return maxLength;
	}
	int lengthOfLongestSubstring(string s) {

		int length = s.size();
		int maxLength = 0;
		int tmpLength = 0;
		unordered_map<char, int> map; //char,int: string中的每个字符和所在的位置
		unordered_map<char, int>::iterator p;
		int i = 0, j = 0;
		for (; i < length; ++i) {
			p = map.find(s.at(i));
			if (p != map.end()) {
				if (p->second >= j) {
					tmpLength = i - j;
					if (tmpLength > maxLength) maxLength = tmpLength;
					j = p->second + 1;
				}
			}
			map[s.at(i)] = i;//insert无法覆盖已经存在的key，[]可以覆盖
		}
		tmpLength = i - j;
		if (tmpLength > maxLength) maxLength = tmpLength;
		return maxLength;
	}
};

int main()
{
	string s[] = { "abcabcbb", "bbbbb","pwwkew", "pwawkew", "pwawkewxy" };
	//answer: 3,1,3,4,6
	Solution solution;
	int num = sizeof(s) / sizeof(string);
	for (int i = 0; i < num; ++i) {
		cout << s[i]<<" max length: " << solution.lengthOfLongestSubstringV1(s[i]);
		cout <<" "<< solution.lengthOfLongestSubstring(s[i])<<endl;
	}
    return 0;
}

