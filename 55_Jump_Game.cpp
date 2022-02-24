/*55. Jump Game
Medium

5398

378

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        int i = 0, j = 0;
        int temp_max;
        while (j < nums.size() - 1){
            temp_max = 0;
            for (int k = i; k <= j; ++k){
                if (k + nums[k] > temp_max)
                    temp_max = k + nums[k];
            }
            if (temp_max <= j)
                return false;
            i = j + 1;
            j = temp_max;
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> nums;

    nums = {2,3,1,1,4};
    cout << "Expect: true" << endl;
    cout << boolalpha << sol.canJump(nums) << endl;

    nums = {3,2,1,0,4};
    cout << "Expect: false" << endl;
    cout << boolalpha <<sol.canJump(nums) << endl;
}