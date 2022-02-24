
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return;
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
    nums = {4,1,2,1,2};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}