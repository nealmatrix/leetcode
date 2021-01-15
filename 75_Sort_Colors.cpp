/*
75. Sort Colors
Medium

4661

267

Add to List

Share
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
 

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?

Solution:
i的起始是-1， j的起始是n， k的起始是0
保持以下3点不变
i 的左边包括i都是0
j 的右边包括j都是2
i与k之间，不包括i和k，都是1
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1;
        int j = nums.size();
        int k = 0;
        int temp;
        while (k < j){
            if (nums[k] == 2){
                temp = nums[j - 1];
                nums[j - 1] = nums[k];
                nums[k] = temp;
                --j;
            }else if (nums[k] == 1){
                ++k;
            }else if (k == i + 1){
                ++i;
                ++k;
            }else{
                temp = nums[i + 1];
                nums[i + 1] = nums[k];
                nums[k] = temp;
                ++i;
            }
        }
    }
};
void printV(vector<int>& nums){
    for (int i = 0; i < nums.size(); ++i){
        cout << nums[i] << ",";
    }
    cout << endl;
}


int main(){
    Solution sol;
    vector<int> nums;

    nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    printV(nums);

    nums = {0};
    sol.sortColors(nums);
    printV(nums);

    nums = {2};
    sol.sortColors(nums);
    printV(nums);

    return 0;
}