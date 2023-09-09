//6 ZigZag Conversion

/* Description:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);*/

/* Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

/* Solution：
i     numRows = 5
0 0 8    16
1 1 7 9  15
2 2 6 10 14
3 3 5 11 13
4 4   12
如上图，行数为i，列数为j
1. i = 0时，第i行第j列对应原来string S序号始终为 (2 * numRows - 2) * j + i
2. i = 1,2,3时，第i行第j列就是第0行减去或者加上i，即序号为 (2 * numRows - 2) * j + sign * i
其中sign = +1 或者 -1
3. i = 4时，第i行第j列对应原来string S序号始终为 (2 * numRows - 2) * j + i
*/

//参考6_zigzag_conversion_2,有两处代码可以修改，更加简洁和清楚

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int n = s.size();
		char* zS = new char[n + 1]; //最后一位加入'\0'，zS为zigzag后的序列,可以改为string，用push_back插入
		int k_zS = 0; //k_zS是zS的序号
		int k_S; //k_S是s的序号
		for (int i = 0; i < numRows; i++) { //i是行号
			int j = 0; //j是列号
			bool need_change_sign = true; // need_change_sign是need change sign
			int sign = 1;
			//第一行和最后一行不需要改变sign
			if (i == 0 || i == numRows - 1)
				need_change_sign = false;
			while (true) {  //是否可以写成while((k_S = (2 * numRows - 2) * j + sign * i) < n)
				k_S = (2 * numRows - 2) * j + sign * i;
				if (k_S < n) {
					zS[k_zS] = s[k_S];
					k_zS++;
					if (need_change_sign) {
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
		zS[k_zS] = '\0';
		string result = zS;
		delete zS;
		return result;
	}
};

int main()
{
	//input
	string s;
	int numRows;
	Solution sol;

	cout << "Expect: PAHNAPLSIIGYIR" << endl;
	s = "PAYPALISHIRING";
	numRows = 3;
	cout << "Output: " << sol.convert(s, numRows) << endl;

	cout << "Expect: PINALSIGYAHRPI" << endl;
	s = "PAYPALISHIRING";
	numRows = 4;
	cout << "Output: " << sol.convert(s, numRows) << endl;

	cout << "Expect: agbfced" << endl;
	s = "abcdefg";
	numRows = 4;
	cout << "Output: " << sol.convert(s, numRows) << endl;

	cout << "Expect: aebdfcg" << endl;
	s = "abcdefg";
	numRows = 3;
	cout << "Output: " << sol.convert(s, numRows) << endl;

	cout << "Expect: A" << endl;
	s = "A";
	numRows = 1;
	cout << "Output: " << sol.convert(s, numRows) << endl;

	system("pause");
    return 0;
}

