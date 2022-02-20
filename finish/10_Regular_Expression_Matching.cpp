//10 Regular Expression Matching

/* Description:
Given an input string (s) and a pattern (p), implement regular expression matching 
with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).*/

/* Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
*/

/* Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. 
Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false*/

/* Solution 1: Dynamic Programming
情况较为复杂，直接参考代码
*/
/* Solution 2：Recursive
和dynamic programming的核心思路一致

Java：
class Solution {
    public boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
}
*/



#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.size();
		int m = p.size();
		//构建（n+1）*（m+1）的二位数组dp
		//dp[i][j]表示s.substr(0, i)和p.substr(0, j)是否match
		bool** dp = new bool*[n + 1];
		for (int i = 0; i < n+1; i++)
			dp[i] = new bool[m + 1];

		//当s为"", p为""时，总是match
		dp[0][0] = true;
		//当p为""，s不为空时，总是not match
		for (int i = 1; i < n + 1; i++)
			dp[i][0] = false;
		
		for (int j = 1; j < m + 1; j++) {
			//只有"a*b*c*"才可以和""match
			//如果前面可以匹配，而j == m了，说明p[j-1]有字符，则不能match
			if (!dp[0][j-1] || j == m || p[j] != '*')
				dp[0][j] = false;
			//每隔一个匹配，""和"a*","a*b*","a*b*c*"匹配
			else {
				j++;
				dp[0][j] = true;
			}
		}
		char slc, plc; //slc: s last character, plc: pattern last character
		for (int i = 1; i< n + 1; i++)
			for (int j = 1; j < m + 1; j++) {
				slc = s[i - 1];
				plc = p[j - 1];
				//s和p最后一位match，且没有*，只有一位match
				if (plc == slc || plc == '.')
					dp[i][j] = dp[i - 1][j - 1];
				else if (plc == '*') {
					//p末两位可以和s最后一位match，且还可能和s的前面位match
					if (p[j - 2] == slc || p[j - 2] == '.')
						//* = 1... || * = 0
						dp[i][j] = dp[i - 1][j] || dp[i][j-2];
					else
						//* = 0
						dp[i][j] = dp[i][j - 2];
				}
				else
					//p最后一位是和s不同的字母，一定不match
					dp[i][j] = false;
			}
		bool result = dp[n][m];
		//leetcode不识别delete
		for (int i = 0; i < n+1; i++)
			delete dp[i];
		delete [] dp;
		return result;
	}
};


int main()
{
	string s, p;
	Solution solu;

	cout << "Expect: false" << endl;
	s = "aa";
	p = "a";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;

	cout << "Expect: true" << endl;
	s = "aa";
	p = "a*";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;

	cout << "Expect: true" << endl;
	s = "ab";
	p = ".*";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;

	cout << "Expect: true" << endl;
	s = "aab";
	p = "c*a*b";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;

	cout << "Expect: false" << endl;
	s = "mississippi";
	p = "mis*is*p*.";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;

	cout << "Expect: true" << endl;
	s = "aaa";
	p = "ab*a*";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;

	cout << "Expect: false" << endl;
	s = "";
	p = ".";
	cout << "Output: " << boolalpha << solu.isMatch(s, p) << endl;
	
	system("pause");
    return 0;
}

