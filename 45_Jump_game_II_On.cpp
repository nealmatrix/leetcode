//45. Jump Game II

/* Description:
Given an array of non-negative integers, you are initially positioned 
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.*/

/*Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

/*Note:
You can assume that you can always reach the last index.*/

/*Solution:
k       0 1 2 3 4 5 6 7 8 9 10
nums    2 1 2 4 3 1 2 4 1 1 4
n_jump  0 1 1 2 2 3 3 3 4 4 4

n_jump表示从第0位开始，需要最小跳多少下到第i位
1. 从第0位开始，n_jump[0] = 0
2. 因为nums[0] == 2，所以1，2位可以从0位直接跳到，那么n_jump[1], n_jump[2] = 1
3. 计算1，2中，哪个k + nums[k]最大，即哪个向后覆盖更广，这里面2位更大，k + nums[k] = 4
4. 即3-4位可以从2位调到，那么n_jump[3], n_jump[4] = 2
5. 重复3，4，直到最后
6. 返回n_jump[len - 1]
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        
        int n_jump = 0; //记录现在最小jump步数
        int i = 0, j = 0; //i，j分别对应新的范围中的最小和最大序号
        int max_i, k; //max_i记录i-j中哪个k+nums[k]最大
        while(j < len - 1){
            for (k = i, max_i = 0; k <= j; ++k){
                if (k + nums[k] > max_i){
                    max_i = min(k + nums[k], len - 1); //最大的范围不可超过len-1
                }
            }
            ++n_jump;
            //重新定义新范围下i和j的值
            i = j + 1;
            j = max_i;
        }
        return n_jump;       
    }
};

int main(){
    vector<int> nums;
    Solution sol;

    cout << "Expect: 2" << endl;
    nums = {2, 3, 1, 1, 4};
    cout << "Output: " << sol.jump(nums) << endl;

    cout << "Expect: 4" << endl;
    nums = {2, 1, 2, 4, 3, 1, 2, 4, 1, 1, 4};
    cout << "Output: " << sol.jump(nums) << endl;

    system("pause");
    return 0; 
}