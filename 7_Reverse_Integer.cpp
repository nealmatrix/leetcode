// 0007 Reverse Integer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class SolutionV1 {
public:
	int reverse(int x) {
		long long max = pow(2, 31) - 1;
		long long min = -pow(2, 31);
		long long result = 0;
		int sign = 1;
		int a; //表示x的个位
		if (x == 0)
			return 0;
		if (x < 0) {
			x = -x;
			sign = -1;
		}
		while (x > 0) {
			a = x % 10;
			result = result * 10 + a;
			x = x / 10;
		}
		result = sign* result;
		if (result > max || result < min)
			return 0;
		return result;
	}
};

class Solution {
public:
	// x<0 和x=0都可以合并
	int reverse(int x) {
		long long max = pow(2, 31) - 1;
		long long min = -pow(2, 31);
		long long result = 0;
		
		while (x != 0) {
			result = result * 10 + x%10;
			x = x / 10;
		}
		if (result > max || result < min)
			return 0;
		return result;
	}
};

int main()
{
	int x;
	Solution solu;
	//test1 return 321
	x = 123;
	cout << solu.reverse(x) << endl;
	//test2 return -321 
	x = -123;
	cout << solu.reverse(x) << endl;
	//test3 return 21
	x = 120;
	cout << solu.reverse(x) << endl;

	//test4 return 0
	x = -pow(2,31);
	cout << solu.reverse(x) << endl;

	long long a;
	cout << sizeof(a) << endl;
	cout << pow(2, 10) << endl;
	cout << (-12) % 10 << endl;
	cout << (-2) % 10 << endl;
    return 0;
}

