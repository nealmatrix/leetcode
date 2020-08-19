#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> jump_num(len, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pair<int, int>top_pq;
        int top_pq_i;
        for (int i = 1; i < len; ++i){
            pq.push(make_pair(jump_num[i - 1], i - 1));
            while (true){
                top_pq = pq.top();
                top_pq_i = top_pq.second;
                if (top_pq_i + nums[top_pq_i] < i){
                    pq.pop();
                }else
                    break;
            }
            top_pq = pq.top();
            jump_num[i] = top_pq.first + 1;
        }
        return jump_num[len - 1];
    }
};

int main(){
    vector<int> nums;
    Solution sol;

    nums = {2,3,1,1,4};
    cout << sol.jump(nums);

    system("pause");
    return 0; 
}