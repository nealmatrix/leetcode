/*
1 1 1 1 2 2 3 4
i j
i       j

1 2 1 1 2 2 3 4
  i       j
  i         j

1 2 3 1 2 2 3 4
    i         j

1 2 3 4 2 2 3 4
      i         j
*/
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 1;
        while (j < len){
            if (nums[i] == nums[j]){
                ++j;
                continue;
            }
            else
                nums[++i] = nums[j++];
        } 
        return i + 1;
    }
};
int printVector(vector<int>& nums){
    int len = nums.size();
    for (int i = 0; i < len; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
int main(){
    Solution sol;
    vector<int> nums;
    nums = {0,0,1,1,1,2,2,3,3,4};
    cout << sol.removeDuplicates(nums) << endl;
    printVector(nums);
    return 0;
}