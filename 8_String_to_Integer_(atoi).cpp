//8 String to Integer (atoi)

/* Description:
Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. 
Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty 
or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value is returned.*/

/* Note:
1. Only the space character ' ' is considered as whitespace character.
2. Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−231,  231 − 1]. 
If the numerical value is out of the range of representable values, 
INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.*/

/* Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−2^31) is returned.*/

#include <string>
#include <iostream>
using namespace std;

class SolutionV1 {
public:
	int myAtoi(string str) {
		//逻辑上可以更加简洁, 参考Solution
		int n = str.size();
		int j = 0; //record the output int 位数
		int i;
		long long result = 0;
		for (i = 0; i < n; i++) {
			if (str[i] != ' ')
				break;
		}
		// str is empty or str contains all whitespace
		if (i == n) 
			return 0;

		if (str[i] != '+' && str[i] != '-' && !isdigit(str[i])) {
			return 0;
		}
		int sign = 1; //记录output是正负的
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') {
				sign = -1;
			}
			i++;
		}
		//str 只有 +/- 号
		if (i == n)
			return 0;
		//str +/-号后不是数字
		if (!isdigit(str[i]))
			return 0;

		for (; i < n; i++) {
			if (isdigit(str[i])) {
				if (result == 0 && str[i] == '0')
					continue;
				result = result * 10 + (str[i] - '0');
				j++;
				if (j > 10)
					break;
			}
			else
				break;
		}
		result = sign * result;
		if (result > INT_MAX)
			return INT_MAX;
		if (result < INT_MIN)
			return INT_MIN;
		return result;
	}
};

class Solution {
public:
	int myAtoi(string str) {
		int n = str.size();
		int j = 0; //record the output int 位数
		int i;
		long long result = 0;
		for (i = 0; i < n; i++) {
			if (str[i] != ' ')
				break;
		}
		// str is empty or str contains all whitespace
		
		int sign = 1; //记录output是正负的
		if (str[i] == '+' || str[i] == '-') {
			sign = (str[i++] == '-') ? -1 : 1;
		}
		
		while (isdigit(str[i]) && i < n) {
			result = result * 10 + (str[i++] - '0');
			if (sign * result > INT_MAX)
				return INT_MAX;
			if (sign * result < INT_MIN)
				return INT_MIN;
		}
		return sign * result;
	}
};


int main()
{

	string str;
	Solution solu;
	//test1 return 0
	str = "";
	cout << solu.myAtoi(str) << ", 0" << endl;

	//test2 return 0
	str = "     ";
	cout << solu.myAtoi(str) << ", 0" << endl;

	//test3 return 42
	str = "42";
	cout << solu.myAtoi(str) << ", 42" << endl;

	//test4 return -42
	str = "      -42";
	cout << solu.myAtoi(str) << ", -42" << endl;

	//test5 return 4193
	str = "4193 with words";
	cout << solu.myAtoi(str) << ", 4193" << endl;

	//test6 return 0
	str = "words and 987";
	cout << solu.myAtoi(str) << ", 0" << endl;

	//test 7 return -2147483648
	str = "-91283472332";
	cout << solu.myAtoi(str) << ", -2147483648" << endl;

	//test 8 return 0
	str = "  ++123";
	cout << solu.myAtoi(str) << ", 0" << endl;

	//test 9 return 0
	str = "   +";
	cout << solu.myAtoi(str) << ", 0" << endl;

	//test 10 return 12345678
	str = "  0000000000012345678";
	cout << solu.myAtoi(str) << ", 12345678" << endl;

	//test 11 return 123
	str = "  00000000000123aa123";
	cout << solu.myAtoi(str) << ", 123" << endl;


	/*cout << isdigit('9')<<endl;
	cout << isalpha('1') << endl;
	cout << dec << pow(2, 31) << endl;
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;*/
    return 0;
}

