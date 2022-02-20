/*
76. Minimum Window Substring
Hard

5838

400

Add to List

Share
Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
 

Constraints:

1 <= s.length, t.length <= 105
s and t consist of English letters.
 

Follow up: Could you find an algorithm that runs in O(n) time?

Solution:
to be clear: substring must contains all the characters of t with the same frequency.
ex: s = "aa", t = "aa", then minWindow output is "aa"

tip: t中的每个字母以及他们的frequency都存储在一个128 dimension的vector中，每个字母对应其ASCII code
这样不用hash也能在O(1)的时间下找到每个字母，比hash更为好的处理方式

1. two pointers left_p and right_p  from start
2. fix left_p, move right_p, till the substring[left_p: right_p) contains all the characters in t
3. fix right_p, move left_p, contract the substring to get the minimum string
4. if move left_p till the substring cannot contain all the characters in t, move right_p again
5. record the minimum substring (or left_p and right_p)
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();

        if (s_length < t_length || t_length == 0)
            return "";
        
        vector<int> s_c(128, 0), t_c(128, 0);
        // Save t in the char - frequency pair form in a vector
        for (char c : t){
            ++t_c[c];
        }

        // s_count: count the number of the characters in substring which are also included in the t
        // s_count is used to know whether substring includes all the characters in the t
        // IMPORTANT: s = "ABAAC", t = "ABC", when right_p == s_length
        // in s_c A:3, B:1, C:1 but s_count = 3
        // A:3 is used for the process of contracting. More A will be removed from substring
        
        // left_min, right_min: save the left and right index of the minimum window
        int left_p = 0, right_p = 0, s_count = 0, min_left = 0, min_right = 0, min_length = s_length + 1;
        char c;
        while (right_p < s_length){
            // Increase right_p in order to find substring under the constraints
            while(right_p < s_length){
                c = s[right_p];
                if (t_c[c] && ++s_c[c] <= t_c[c]){
                    ++s_count;
                }
                ++right_p;

                if (s_count == t_length)
                    break;
            }

            if (s_count < t_length)
                break;

            // Contract left_p
            while (left_p < right_p){
                ++left_p;
                c = s[left_p - 1];
                if (t_c[c] && --s_c[c] < t_c[c]){
                    --s_count;
                    break;
                }
            }
            if (right_p - left_p + 1 < min_length){
                min_left = left_p - 1;
                min_right = right_p;
                min_length = min_right - min_left;
            }
        }
        if (min_length == s_length + 1)
            return "";
        else
            return s.substr(min_left, min_length);
    }
};

int main(){
    string s, t;
    Solution sol;

    s = "ANBAACBAB";
    t = "ABC";
    cout << "Expect: ACB" << endl;
    cout << sol.minWindow(s, t) << endl;

    s = "ADOBECODEBANC", t = "ABC";
    cout << "Expect: BANC" << endl;
    cout << sol.minWindow(s, t) << endl;

    s = "aa", t = "aa";
    cout << "Expect: aa" << endl;
    cout << sol.minWindow(s, t) << endl;

    return 0;
}