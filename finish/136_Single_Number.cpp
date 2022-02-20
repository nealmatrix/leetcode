
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const auto & num: nums){
            result ^= num;
        }        
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums;
    nums = {4,1,2,1,2};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}