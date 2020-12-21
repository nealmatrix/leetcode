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
0  1  2 3  4 5 6  7 8 
-2,1,-3,4,-1,2,1,-5,4

i   temp    max
0   -2      -2
1   1       1
2   -2      1
3   4       4
4   3       4
5   5       5
6   6       6
7   1       6
8   5       6   
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int max = nums[i];
        int temp = max;
        while ((++i) < nums.size()){
            if (temp < 0){
                if (nums[i] > temp){
                    temp = nums[i];
                    
                }
            }else{
                temp += nums[i];
            }
            if (temp > max){
                max = temp;
            }
        }
        return max;
    }
};

int main(){
    Solution sol;
    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Expect: 6" << endl;
    cout << sol.maxSubArray(nums) << endl;

    nums = {-11, -12, -5, 1};
    cout << "Expect: 1" << endl;
    cout << sol.maxSubArray(nums) << endl;
}