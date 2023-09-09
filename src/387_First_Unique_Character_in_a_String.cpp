#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    const int CHAR_NUM = 26;
    int firstUniqChar(string s){
        //char_list 存储string s每个字符出现的频率，再从头loop字符串取频率为1的
        int char_list[CHAR_NUM];
        for (int i = 0; i < CHAR_NUM; ++i)
            char_list[i] = 0;

        for (int i = 0; i < s.length(); ++i){
            ++char_list[s[i] - 'a'];
        }

        for (int i = 0; i < s.length(); ++i){
            if (char_list[s[i] - 'a'] == 1)
                return i; 
        }
        return -1;
    }

    int firstUniqChar_v1(string s) {
        //char_list存储string s每个字符的序号，再从头loop char_list取符合条件且序号小的
        //char_list值: -1为从未出现过， -2出现过2次或者2次以上，其他的为只出现一次，且存储的是字符在s中的序号
        int char_list[CHAR_NUM];
        for (int i = 0; i < CHAR_NUM; ++i)
            char_list[i] = -1;

        int s_i;       
        for (int i = 0; i < s.length(); ++i){
            s_i = s[i] - 'a';
            if (char_list[s_i] == -1)
                char_list[s_i] = i;
            else if (char_list[s_i] >= 0)
                char_list[s_i] = -2;
        } 
        int result = -1;
        int char_list_v;
        for (int i = 0; i < CHAR_NUM; ++i){
            char_list_v = char_list[i];
            if (char_list_v >= 0){
                if (result == -1)
                    result = char_list_v;
                else if (char_list_v < result)
                    result = char_list_v;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    s = "leetcode";
    cout << sol.firstUniqChar(s) << endl;

    s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl;
    s = "aabb";
    cout << sol.firstUniqChar(s) << endl;
    s = "aabbb";
    cout << sol.firstUniqChar(s) << endl;
    return 0;
}