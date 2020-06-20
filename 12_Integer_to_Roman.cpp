//12 Integer to Roman

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

Given an integer, convert it to a roman numeral. Input is guaranteed to be within 
the range from 1 to 3999.*/

/* Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.*/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		//I V  X  L  C   D   M
		//1 5 10 50 100 500 1000
		unordered_map<int, string> intToRoMap;
		insertItem1("I", "V", "X", 1, intToRoMap);
		insertItem1("X", "L", "C", 10, intToRoMap);
		insertItem1("C", "D", "M", 100, intToRoMap);
		insertItem2(intToRoMap);
		//printUnorderMap(intToRoMap);
		int order = 1;
		int i; //记录num的最低位
		string result = "";
		while (num > 0) {
			i = num % 10;
			result = intToRoMap[i*order] + result;
			num /= 10;
			order *= 10;
		}
		return result;
		
	}
	void insertItem1(string c1, string c2, string c3, int order, unordered_map<int, string>& map) {
		//c1,c2,c3 is corresponding to "I","V","X", when order is 1
		//c1,c2,c3 is corresponding to "X","L","C", when order is 10
		//c1, c2, c3 is corresponding to "C", "D", "M", when order is 100
		int num[] = { 0,1,2,3,4,5,6,7,8,9 };
		for (int i = 0; i < 10; i++) {
			num[i] = num[i] * order;
		}
		map.insert(make_pair(num[1], c1));			//1 ->"I"
		map.insert(make_pair(num[2], c1+c1)); 		//2 ->"II"
		map.insert(make_pair(num[3], c1+c1+c1));	//3 ->"III"
		map.insert(make_pair(num[4], c1+c2));		//4 ->"IV"
		map.insert(make_pair(num[5], c2));			//5 ->"V"
		map.insert(make_pair(num[6], c2+c1));		//6 ->"VI"
		map.insert(make_pair(num[7], c2+c1+c1));	//7 ->"VII"
		map.insert(make_pair(num[8], c2+c1+c1+c1));	//8 ->"VIII"
		map.insert(make_pair(num[9], c1+c3));		//9 ->"IX"
	}
	void insertItem2(unordered_map<int, string>& map) {
		map.insert(make_pair(1000, "M"));
		map.insert(make_pair(2000, "MM"));
		map.insert(make_pair(3000, "MMM"));
		map.insert(make_pair(0, ""));
	}
	/*template<class K, class V>
	void printUnorderMap(unordered_map<K, V>& map) {
		unordered_map<K, V>::iterator p;
		for (p = map.begin(); p != map.end(); ++p) {
			cout << p->first << ", " << p->second << endl;
		}
	}*/

};


int main()
{
	Solution solu;
	int num;

	cout << "Expect: III" <<endl;
	num = 3;
	cout << "Output: " << solu.intToRoman(num) << endl;
	
	cout << "Expect: IV" <<endl;
	num = 4;
	cout << "Output: " << solu.intToRoman(num) << endl;
	
	cout << "Expect: IX" <<endl;
	num = 9;
	cout << "Output: " << solu.intToRoman(num) << endl;

	cout << "Expect: LVIII" <<endl;
	num = 58;
	cout << "Output: " << solu.intToRoman(num) << endl;
	
	cout << "Expect: MCMXCIV" <<endl;
	num = 1994;
	cout << "Output: " << solu.intToRoman(num) << endl;

	cout << "Expect: MM" <<endl;
	num = 2000;
	cout << "Output: " << solu.intToRoman(num) << endl;

	system("pause");
    return 0;
}

