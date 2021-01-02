/*64. Minimum Path Sum
Medium

4013

77

Add to List

Share
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //动态分配二维数组
        int **mps = new int *[m];
        for (int i = 0; i < m; ++i){
            mps[i] = new int[n];
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (i == 0 && j != 0){
                    mps[i][j] = mps[i][j - 1] + grid[i][j];
                }else if (i != 0 && j == 0){
                    mps[i][j] = mps[i - 1][j] + grid[i][j];
                }else if (i != 0 && j != 0){
                    mps[i][j] = min(mps[i][j - 1], mps[i - 1][j]) + grid[i][j];
                }else
                    mps[i][j] = grid[0][0];
            }
        }

        int result = mps[m - 1][n - 1];

        //delete pointer
        for (int i = 0; i < m; ++i){
            delete [] mps[i];
        }
        delete [] mps;

        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid;

    grid =  { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
    cout << "Expect: 7" << endl;
    cout << sol.minPathSum(grid) << endl;

    grid = {{1,2,3},{4,5,6}};
    cout << "Expect: 12" << endl;
    cout << sol.minPathSum(grid) << endl;
    
    return 0;
}
