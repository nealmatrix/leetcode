#ifndef LEETCODE_SOLUTIONS_HPP_ 
#define LEETCODE_SOLUTIONS_HPP_ 

#include <vector>
#include <unordered_map>

namespace leetcode
{

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map; //int,int -> a[i], i
        std::vector<int> result;

        for (std::vector<int>::iterator p = nums.begin(); p != nums.end(); ++p)
        {
            int target2 = target - *p;

            std::unordered_map<int, int>::iterator q = map.find(target2);

            if (q != map.end())
            {
                result.push_back(q->second);
                result.push_back(p - nums.begin());
                break;
            }
            map.insert(std::make_pair(*p, p - nums.begin()));
        }
        return result;
    }
};

} // namespace leetcode

#endif