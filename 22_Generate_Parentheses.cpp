//22 Generate Parentheses

/* Description:
Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses.*/

/* Example:
given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/

/* Solution 1：Recursive 
1. set好base case后，
2. 我们先得到n-1的结果，为了避免重复，需要在n-1的结果中，查询到最后一个'('
出现的位置，然后在其后的每个位置都可以插入一对'('')'，因为这对括号的'('是最后出现的，所以其')'必须要
马上跟着他的'('，所以这对括号是要一起出现。*/

/* Solution 2: Backtracking
Instead of adding '(' or ')' every time as in Approach 1, let's only add them when we know 
it will remain a valid sequence. We can do this by keeping track of the number of 
opening and closing brackets we have placed so far.

We can start an opening bracket if we still have one (of n) left to place. 
And we can start a closing bracket if it would not exceed the number of opening brackets.

Python:
def backtrack(S = '', left = 0, right = 0):
    if len(S) == 2 * N:
        ans.append(S)
        return
    if left < N:
        backtrack(S+'(', left+1, right)
    if right < left:
        backtrack(S+')', left, right+1)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strs_n;
        if (n == 0)
            return strs_n;
        if (n == 1){
            strs_n.push_back("()");
            return strs_n;
        }
        vector<string> strs_n_1 = generateParenthesis(n - 1);//save n-1 strings
        for(const auto & str_n_1 : strs_n_1){
            int length = str_n_1.length();
            int i = length - 1;
            for (; i >= 0; --i){
                if (str_n_1[i] == '(')
                    break;
            }
            string str_n;
            for (int j = i; j < length; ++j){
                str_n = str_n_1.substr(0, j + 1) + "()" + str_n_1.substr(j + 1);
                strs_n.push_back(str_n);
            }
        }
        return strs_n;
    }
};

//print vector
void printVector(vector<string> & strs){
    for(const auto & str : strs){
        std::cout << str << endl;
    }
}
int main(){
    int n;
    Solution sol;
    vector<string> strs_n;
    vector<string> strs;

    std::cout << "Expect: " << endl;
    strs = {"((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"};
    
    printVector(strs);
    std::cout << "Output: " << endl;
    n = 3;
    strs_n = sol.generateParenthesis(n);
    printVector(strs_n);

    std::cout << "Expect: " << endl;
    strs = {"(())",
            "()()"};
    
    printVector(strs);
    std::cout << "Output: " << endl;
    n = 2;
    strs_n = sol.generateParenthesis(n);
    printVector(strs_n);
    

    system("pause");
    return 0;
}