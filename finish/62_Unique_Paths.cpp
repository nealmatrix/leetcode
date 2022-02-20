/*62. Unique Paths
Medium

4306

232

Add to List

Share
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Example 3:
Input: m = 7, n = 3
Output: 28

Example 4:
Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // if (m == 1 || n == 1)
        //     return 1;
        
        //动态分配二维数组
        int **up = new int*[m + 1];
        for (int i = 0; i <= m; ++i){
            up[i] = new int[n + 1];
        }

        //当m=1或者n=1时，结果都是1
        // for (int j = 1; j <= n; ++j){
        //     up[1][j] = 1;
        // }
        // for (int i = 1; i <= m; ++i){
        //     up[i][1] = 1;
        // }
        
        // //dynamic programming，计算其他值
        // for (int i = 2; i <= m; ++i){
        //     for (int j = 2; j <= n; ++j){
        //         up[i][j] = up[i - 1][j] + up[i][j - 1];
        //     }
        // }
        
        //整合了上面的代码为下面的一个双重循环
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j<= n; ++j){
                if (i == 1 || j == 1)
                    up[i][j] = 1;
                else{
                    up[i][j] = up[i - 1][j] + up[i][j - 1];
                }
            }
        }
        //保存结果，因为一会要先释放空间，再返回
        int result = up[m][n];

        //释放动态分配的指针
        for (int i = 0; i <= m; ++i){
            delete [] up[i];
        }
        delete [] up;

        //return结果
        return result;
    }
};
int main(){
    int m, n;
    Solution sol;

    m = 7, n = 3;
    cout << "Expect: 28" << endl;
    cout << sol.uniquePaths(m, n) << endl;

    m = 3, n = 7;
    cout << "Expect: 28" << endl;
    cout << sol.uniquePaths(m, n) << endl;

    m = 3, n = 2;
    cout << "Expect: 3" << endl;
    cout << sol.uniquePaths(m, n) << endl;
    
    m = 3, n = 3;
    cout << "Expect: 6" << endl;
    cout << sol.uniquePaths(m, n) << endl;

    return 0;
}