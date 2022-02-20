//13 Roman to Integer
/* Description:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. 
Input is guaranteed to be within the range from 1 to 3999.

/*Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution_2 {
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
				//如果i+1位比i位大，说明是4, 9, 40, 90...其值就是j
				//注意++i；
				if (j > 0) {
					result += j;
					++i;
				}
				//如果i+1位比i位小，说明i位即是正常相加
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

	cout << "Expect: 3" << endl;
	s = "III";
	cout << "Output: " << solu.romanToInt(s) << endl;
	
	cout << "Expect: 4" << endl;
	s = "IV";
	cout << "Output: " << solu.romanToInt(s) << endl;
	
	cout << "Expect: 9" << endl;
	s = "IX";
	cout << "Output: " << solu.romanToInt(s) << endl;

	cout << "Expect: 58" << endl;
	s = "LVIII";
	cout << "Output: " << solu.romanToInt(s) << endl;
	
	cout << "Expect: 1994" << endl;
	s = "MCMXCIV";
	cout << "Output: " << solu.romanToInt(s) << endl;

	cout << "Expect: 2000" << endl;
	s = "MM";
	cout << "Output: " << solu.romanToInt(s) << endl;

	system("pause");
    return 0;
}

