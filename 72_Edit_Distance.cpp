/*
72. Edit Distance
Hard

4971

66

Add to List

Share
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // Create 2-D table
        int **md = new int*[m + 1];
        for (int i = 0; i <= m; ++i){
            md[i] = new int[n + 1];
        }

        // Base case
        for (int i = 0; i <= m; ++i){
            md[i][0] = i;
        }
        for (int j = 0; j <= n; ++j){
            md[0][j] = j;
        }

        int gap;
        // Dynamic Programming
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (word1[i - 1] == word2[j - 1])
                    gap = 0;
                else
                    gap = 1;
                md[i][j] = min({md[i - 1][j - 1] + gap, md[i][j - 1] + 1, md[i - 1][j] + 1});
            }
        }

        int result = md[m][n];
        // Delete point
        for (int i = 0; i <=m; ++i){
            delete [] md[i];
        }
        delete [] md;

        return result;
    }
};

int main(){
    string word1, word2;
    Solution sol;

    word1 = "horse", word2 = "ros";
    cout << sol.minDistance(word1, word2) << endl; 

    word1 = "intention", word2 = "execution";
    cout << sol.minDistance(word1, word2) << endl; 
    
    return 0;
}