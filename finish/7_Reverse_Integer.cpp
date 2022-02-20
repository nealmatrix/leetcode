//7 Reverse Integer

/* Description:
Given a 32-bit signed integer, reverse digits of an integer.*/

/* Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21*/

/* Note:
Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 
when the reversed integer overflows.*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution_2 {
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
	// x < 0 和x = 0 都可以合并
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

	cout << "Expect: 321" << endl;
	x = 123;
	cout << "Output: " << solu.reverse(x) << endl;
	
	cout << "Expect: -321" << endl;
	x = -123;
	cout << "Output: " << solu.reverse(x) << endl;
	
	cout << "Expect: 21" << endl;
	x = 120;
	cout << "Output: " << solu.reverse(x) << endl;

	cout << "Expect: 0" << endl;
	x = -pow(2,31);
	cout << "Output: " << solu.reverse(x) << endl;

	long long a;
	cout << sizeof(a) << endl;
	cout << pow(2, 10) << endl;
	cout << (-12) % 10 << endl;
	cout << (-2) % 10 << endl;
    return 0;
}

