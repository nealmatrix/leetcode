/*53. Maximum Subarray
Easy

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
*/

/* Solution:
1. 复杂度为O(n)
j为隐藏参数，在程序中没有
temp为  从j开始，到i结束的subarray的和（包括i
1. if temp < 0, 那么temp就取下一个nums[i]，因为之前temp这部分一定不会给后面带来收益
2. if temp >= 0，那么temp就加下一个nums[i]，因为之前的temp会增加总和
3. 保留最大的temp


0  1  2 3  4 5 6  7 8 
-2,1,-3,4,-1,2,1,-5,4

i   temp    max j
0   -2      -2  0
1   1       1   1
2   -2      1   1
3   4       4   3
4   3       4   3
5   5       5   3
6   6       6   3
7   1       6   3
8   5       6   3

2. divide and conquer 复杂度为O(nlogn)
1. 将nums从中间分开，左右分别带入函数，得到最大的maxSubArray
2. 计算一定横跨两个左右的subarray的最大值，即从mid开始，左边的最大值加右边的最大值，复杂度为O(n)
3. 输出这三个中最大的即是结果

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int maxValue = nums[i];
        int temp = maxValue;
        while ((++i) < nums.size()){
            if (temp < 0){
                temp = nums[i];
            }else{
                temp += nums[i];
            }
            if (temp > maxValue){
                maxValue = temp;
            }
        }
        return maxValue;
    }

    int maxSubArray_v2(vector<int>& nums){
        return maxDivideAndConquer(nums, 0, nums.size() - 1);
    }

    int maxDivideAndConquer(vector<int>& nums, int i, int j){
        //nums[i: j + 1] i <= j
        if (i == j)
            return nums[i];
        int mid = (i + j)/2;
        int leftMaxSubArray = maxDivideAndConquer(nums, i, mid);
        int rightMaxSubArray = maxDivideAndConquer(nums, mid + 1, j);
        int leftMax = nums[mid];
        int rightMax = nums[mid + 1];
        int temp = 0;
        for(int k = mid; k >= i; --k){
            temp += nums[k];
            if (temp > leftMax)
                leftMax = temp;
        }
        temp = 0;
        for (int k = mid + 1; k <= j; ++k){
            temp += nums[k];
            if (temp > rightMax)
                rightMax = temp;
        }
        return max(max(leftMaxSubArray, rightMaxSubArray), rightMax + leftMax);
    }
};

int main(){
    Solution sol;
    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Expect: 6" << endl;
    cout << "Output: " << sol.maxSubArray(nums) << endl;
    cout << sol.maxSubArray_v2(nums) << endl;

    nums = {-11, -12, -5, 1};
    cout << "Expect: 1" << endl;
    cout << sol.maxSubArray(nums) << endl;
    cout << sol.maxSubArray_v2(nums) << endl;

    cout << 1/2 << endl;
}