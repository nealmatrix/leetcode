//9 Palindrome Number
/* Description:
Determine whether an integer is a palindrome. 
An integer is a palindrome when it reads the same backward as forward.*/

/* Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.*/

/*Follow up:
Coud you solve it without converting the integer to a string?*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome_2(int x) {
		string s = to_string(x);
		int n = s.size();
		int minI, maxI;
		if (n % 2 == 0) {
			minI = n / 2 - 1;
			maxI = n / 2;
		}
		else {
			minI = maxI = (n - 1) / 2;
		}
		int j = 0;
		while (minI - j >= 0 && maxI + j <= n - 1) {
			if (s[minI - j] != s[maxI + j])
				return false;
			j++;
		}
		return true;
	}

	bool isPalindrome(int x) {
		std::string orig = std::to_string(x);
		// Make a copy of it
		std::string rev(orig);
		// which is the same as
		// std::string rev = orig;

		// Reverse it
		std::reverse(rev.begin(), rev.end());

		return (orig == rev);
	}
};

int main()
{
	Solution solu;
	int x;

	cout << "Expect: true" << endl;
	x = 121;
	cout << "Output: " << boolalpha << solu.isPalindrome(x) << endl;

	cout << "Expect: false" << endl;
	x = -121;
	cout << "Output: " << boolalpha << solu.isPalindrome(x) << endl;
	
	cout << "Expect: false" << endl;
	x = 10;
	cout << "Output: " << boolalpha << solu.isPalindrome(x) << endl;
    
	system("pause");
	return 0;
}

