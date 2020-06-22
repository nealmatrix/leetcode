//32. Longest Valid Parentheses

/* Description:
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.*/

/* Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"*/

/* Solution: 本次编程用stack方法
1. 遇到'('就push其index入stack
2. 遇到')' 
- 如果stack为empty，就push ')'
- 如果stack不为empty，就top stack得到最上面的元素
- 如果最上面的元素是'('即pop
    - 如果此时stk为empty, 则本次valid parentheses的length为')'的index + 1
    - 如果此时stk不为empty，用')'的index减去pop后stack最上面的元素的index，为这次的length
- 如果最上面的元素是')'，则继续push本次的')'
3. 取所有length中最大的*/

/* 例如如下string:
( ( ) ( ( ) ( )
0 1 2 3 4 5 6 7
stack:
-1 0 1      遇到2，pop 1
   0        计算length为2-0=2
   0 3 4    遇到5，pop 4
   0 3      计算length为5-3=2
   0 3 6    遇到7，pop 6
   0 3      计算length为7-3=4
最长length为4
*/

/* Note:
1. 因为如果无法配对的括号会一直留在stack中，自动成为计算之后的valid parenthese length的起点
2. 复杂度为O(n), scan一遍string，需要额外O(n)的空间存储stack
3. 有另一种算法不需要额外空间，在32的markdown中介绍和证明*/

#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len_s = s.size();
        stack<int> stk;
        int i_top;
        int max_len = 0;
        int len;
        
        for (int i = 0; i < len_s; ++i){
            //1. 遇到'('就push其index入stack
            if (s[i] == '(')
                stk.push(i);
            //2. 遇到')
            else{
                //如果stack为empty，就push ')'
                if (stk.empty())
                    stk.push(i);
                //如果stack不为empty，就top stack得到最上面的元素
                else{
                    i_top = stk.top();
                    //如果最上面的元素是'('即pop，
                    if (s[i_top] == '('){
                        stk.pop();
                        //如果此时stk为empty, 则本次valid parentheses的length为')'的index + 1
                        if (stk.empty())
                            len = i + 1;
                        //如果此时stk不为empty，用')'的index减去pop后stack最上面的元素的index
                        //为这次的length
                        else
                            len = i - stk.top();
                        if (len > max_len)
                            max_len = len;
                    //如果最上面的元素是')'，则继续push本次的')'
                    }else
                        stk.push(i);
                }
            }
        }
        return max_len;
    }
};

int main(){
    string s;
    Solution sol;

    cout << "Expect: 2" << endl;
    s = "(()";
    cout << "Output: " << sol.longestValidParentheses(s) << endl;

    cout << "Expect: 4" << endl;
    s = ")()())";
    cout << "Output: " << sol.longestValidParentheses(s) << endl;
    
    cout << "Expect: ?" << endl;
    s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    cout << "Output: " << sol.longestValidParentheses(s) << endl;
    system("pause");
    return 0;
}