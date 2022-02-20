
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        int k = 0;
        int pre, d;
        
        while (i < len){
            d = 0;
            pre = nums[i];
            int j = i + 1;
            while (j < len){
                if (nums[j] == pre){
                    ++j;
                    ++d;
                }
                else
                    break;
            }
            while (j < len){
                nums[j - d] = nums[j];
                ++j;
            }
            len -= d;
            ++i;
            ++k;
        }
        return k;
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