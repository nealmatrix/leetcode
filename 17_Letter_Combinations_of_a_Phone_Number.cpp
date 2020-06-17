//17 Letter Combinations of a Phone Number

/* Description:
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.*/

/* Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/

/* Note:
Although the above answer is in lexicographical order, 
your answer could be in any order you want.*/

/* Solution:
recursion:设定好base case后，digits的combinations结果相当于
digits[0] (string(1, digits[0]))和digits[1:] (digits.substr(1)) 的结果组合*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map<string, string> dmap({{"2", "abc"}, 
                                  {"3", "def"},
                                  {"4", "ghi"},
                                  {"5", "jkl"},
                                  {"6", "mno"},
                                  {"7", "pqrs"},
                                  {"8", "tuv"},
                                  {"9", "wxyz"}});
        //base case:
        if (digits == "")
            return result;

        int d_num =  digits.length();
        if (d_num == 1){
            string alpha = dmap[digits];
            for (int j = 0; j < alpha.length(); ++j)
                result.push_back(string(1, alpha[j]));
            return result;
        }
        //recursion:
        string f_dig(1, digits[0]);
        string alpha = dmap[f_dig];
        //temp_result为去掉首字母的string对应的字母表
        vector<string> strings_1 = letterCombinations(digits.substr(1));
        for (int i = 0; i < alpha.length(); ++i){
            for (string& string_1: strings_1){
                result.push_back(alpha[i] + string_1);
            }
        }
        return result;
    }
};
void print_vectors(vector<string> strs){
    for (string& str: strs)
        cout << str << ',';
    cout << endl;
}

int main(){
    string digits;
    Solution s;
    //case 1:
    cout << "case 1: output [ad, ae, af, bd, be, bf, cd, ce, cf]" << endl;
    digits = "23";
    print_vectors(s.letterCombinations(digits));
    //case 2:
    cout << "case 2: output []" << endl;
    digits = "";
    print_vectors(s.letterCombinations(digits));

    system("pause");
    return 0;
}