//20 Valid Parentheses

/* Description:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.*/

/* Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true*/

/* Solution:
用容器适配器stack，后进先出，从string s左到右进行scan
1. 如果是'(','{','['，就push进stack
2. 如果是')','}',']'，就用stack的top()判断是否和其对应
注意要先判断stack是否是empty，比如s = ']'，stack为empty结果也是false
3. 结尾判断如果stack为empty就是true，否则为false
*/

#include <iostream>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> parentheses({{')', '('},
                                     {'}', '{'},
                                     {']', '['}});
        stack<char> stk;
        for (unsigned int i = 0; i < s.length(); ++i){
            //1. 如果是'(','{','['，就push进stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            else{
                //如果是')','}',']'，就用stack的top()判断是否和其对应
                //注意要先判断stack是否是empty，比如s = ']'，stack为empty结果也是false
                if (stk.empty() || parentheses[s[i]] != stk.top())
                    return false;
                else{
                    stk.pop();
                }
            }
        }
        //结尾判断如果stack为empty就是true，否则为false
        if (stk.empty())
            return true;
        else
            return false;
    }
};

int main(){
    string s;

    Solution sol;

    cout << "Expected: false" << endl;
    s = "]";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: true" << endl;
    s = "()";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: true" << endl;
    s = "()[]{}";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: false" << endl;
    s = "(]";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: false" << endl;
    s = "([)]";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: true" << endl;
    s = "{[]}";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: false" << endl;
    s = "[";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    cout << "Expected: false" << endl;
    s = "[])";
    cout << "Output:" << boolalpha << sol.isValid(s) << endl;

    system("pause");
    return 0;
}