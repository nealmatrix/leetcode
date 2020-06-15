// 0012 Integer to Roman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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

	//test1 return "III"
	num = 3;
	cout << solu.intToRoman(num) << ", III" << endl;
	
	//test2 return "IV"
	num = 4;
	cout << solu.intToRoman(num) << ", IV" << endl;
	
	//test3 return "IX"
	num = 9;
	cout << solu.intToRoman(num) << ", IX" << endl;

	//test4 return "LVIII"
	num = 58;
	cout << solu.intToRoman(num) << ", LVIII" << endl;
	
	//test5 return "MCMXCIV"
	num = 1994;
	cout << solu.intToRoman(num) << ", MCMXCIV" << endl;

	//test6 return "MM"
	num = 2000;
	cout << solu.intToRoman(num) << ", MM" << endl;

    return 0;
}

