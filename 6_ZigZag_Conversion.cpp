// 0006 ZigZag Conversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int n = s.size();
		char* zS = new char[n+1]; //最后一位加入'\0'
		int k = 0; //k是zS的序号
		int kS; //kS是s的序号
		for (int i = 0; i < numRows; i++) { //i是行号
			int j = 0; //j是每行的序号
			bool nCSign = true; // nCSign是need change sign
			int sign = 1;
			if (i == 0 || i == numRows - 1)
				nCSign = false;
			while (true) {
				kS = (2 * numRows - 2)*j + sign*i;
				if (kS < n) {
					zS[k] = s[kS];
					k++;
					if (nCSign) {
						if (sign == 1)
							j++, sign = -1;
						else
							sign = 1;
					}
					else {
						j++;
					}
				}
				else
					break;
			}
		}
		zS[k] = '\0';
		string result = zS;
		delete zS;
		return result;
	}
};

int main()
{
	string s;
	int numRows;
	//test1 return "PAHNAPLSIIGYIR"
	s = "PAYPALISHIRING";
	numRows = 3;

    //test2 return "PINALSIGYAHRPI"
	s = "PAYPALISHIRING";
	numRows = 4;

	//test3 return "agbfced"
	/*s = "abcdefg";
	numRows = 4;*/

	//test4 return "aebdfcg"
	/*s = "abcdefg";
	numRows = 3;*/

	//test5 return "A"
	s = "A";
	numRows = 1;

	Solution solu;
	cout << solu.convert(s, numRows)<<endl;

	/*char s[10] = "abc";
	string a = s;
	cout << s<<","<<a << endl;*/
    return 0;
}

