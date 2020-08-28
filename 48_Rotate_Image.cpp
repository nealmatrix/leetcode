//48. Rotate Image
/*Description:
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).*/

/*Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.*/

/*Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]*/
/* Solution: recursion
1. 构造新的函数rotateWithFour，加入row begin end的序号和col begin end序号
   表示在序号内的正方形被rotate了
2. set base case
3. 调用rotateWithFour(matrix, row_begin + 1, row_end - 1, col_begin + 1, col_end - 1)
   将里面的正方形rotate
4. rotate最外面一圈
5. 如下图将最外面一圈分为四部分(2,3), (1,4), (7,8), (9,6)
6. (2,3)交换(1,4)， (7,8)再和(1,4)位置的交换， (9,6)再和(7,8)位置的交换，这样最外面一圈即rotate 90度

1 2 3
4 5 6 
7 8 9
->
3 4 1
2 5 6
7 8 9
->
7 4 1
8 5 6
3 2 9
->
7 4 1
8 5 2
9 6 3

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        rotateWithFour(matrix, 0, n - 1, 0, n - 1);
    }
    void rotateWithFour(vector<vector<int>>& matrix, \
                        int row_begin, \
                        int row_end, \
                        int col_begin, \
                        int col_end){
        
        int n = row_end - row_begin + 1;
        //base case
        if (n <= 1)
            return;
        //rotate 内部正方形
        rotateWithFour(matrix, row_begin + 1, row_end - 1, col_begin + 1, col_end - 1);
        int temp;

        //rotate 最外圈
        for (int i = 0; i < n - 1; ++i){
            temp = matrix[row_begin][col_end - i];
            matrix[row_begin][col_end - i] = matrix[row_begin + i][col_begin];
            matrix[row_begin + i][col_begin] = temp;
        }

        for (int i = 0; i < n - 1; ++i){
            temp = matrix[row_begin + i][col_begin];
            matrix[row_begin + i][col_begin] = matrix[row_end][col_begin + i];
            matrix[row_end][col_begin + i] = temp;
        }

        for (int i = 0; i < n - 1; ++i){
            temp = matrix[row_end][col_begin + i];
            matrix[row_end][col_begin + i] = matrix[row_end - i][col_end];
            matrix[row_end - i][col_end] = temp;
        }
        return;                   

    }
};
void printMatrix(vector<vector<int>> matrix){
    for (unsigned int i = 0; i < matrix.size(); ++i){
        for (unsigned int j = 0; j < matrix[i].size(); ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> matrix;
    Solution sol;
    
    matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    sol.rotate(matrix);
    printMatrix(matrix);

    matrix = {{5, 1, 9,11}, {2, 4, 8,10}, {13, 3, 6, 7}, {15,14,12,16}};
    sol.rotate(matrix);
    printMatrix(matrix); 

    system("pause");
}