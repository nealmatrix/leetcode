//49. Group Anagrams
/*Description
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
/*
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]*/
 
/*Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.*/

/*Solution:
1. 将str中的字母按照从小到大的顺序排序
2. 将排好序的字母为Key，存入unordered_map中
3. 取unordered_map的value为结果*/

#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams_v1(vector<string>& strs) {
    //比较map很费时
        vector<vector<string>> result;
        vector<map<char, int>> temp_vector;
        map<char, int> temp_map;
        int i;
        for (const auto & str: strs){
            temp_map.erase(temp_map.begin(), temp_map.end());
            for (i = 0; i < str.length(); ++i){
                temp_map[str[i]] += 1;
            }
            for (i = 0; i < temp_vector.size(); ++i){
                if (temp_vector[i] == temp_map){
                    result[i].push_back(str);
                    break;
                }
            }
            if (i == temp_vector.size()){
                temp_vector.push_back(temp_map);
                result.push_back({str});
            }
        }
        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> strToStrs;
        int i;
        for ( string& str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            strToStrs[temp].push_back(str);
        }

        for (auto & element: strToStrs){
            result.push_back(element.second);
        }
        return result;
    }
};
//和==操作符的作用一样
bool mapCompare(map<char, int>& map1, map<char, int>& map2){
    map<char, int>::iterator map1_i = map1.begin(), map2_i = map2.begin();
    while(map1_i != map1.end() && map2_i != map2.end()){
        if (map1_i -> first != map2_i -> first || map1_i ->second != map2_i -> second)
            return false;
        ++map1_i;
        ++map2_i;
    }
    if (map1_i == map1.end() && map2_i == map2.end())
        return true;
    else
        return false; 
}

int print(vector<vector<string>>& strs){
    for (int i = 0; i < strs.size(); ++i){
        for (int j = 0; j < strs[i].size(); ++j){
            cout << strs[i][j] << ',';
        }
        cout << endl;
    }
}

int main(){
    Solution sol;
    vector<vector<string>> result;
    vector<string> strs;

    string s = "bca";
    sort(s.begin(), s.end());
    cout << s << endl;

    strs = {"eat","tea","tan","ate","nat","bat"};
    cout << "Expect: " << "[bat], [nat, tan], [ate, eat, tea]" << endl;
    result = sol.groupAnagrams(strs);
    cout << "Output:\n";
    print(result);

    strs = {""};
    cout << "Expect: [""]" << endl;
    result = sol.groupAnagrams(strs);
    cout << "Output:\n";
    print(result);

    strs = {"a"};
    cout << "Expect: [a]" << endl;
    result = sol.groupAnagrams(strs);
    cout << "Output:\n";
    print(result);
    return 0;
}