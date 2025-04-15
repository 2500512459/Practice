/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值target的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 错误写法，没有考虑到重复的情况
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            map<int, int> myMap;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                myMap[nums[i]] = i;
            }
            for (auto it = myMap.begin(); it != myMap.end(); ++it) {
                if(myMap.find(target - it->first) != myMap.end())
                {
                    result.push_back(it->second);
                    result.push_back(myMap[target - it->first]);
                    break;
                }
            }
            return result;
        }
};
// 正确写法，每次存入元素前先判断是否已存在另一个元素
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            map<int, int> myMap;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                int complement = target - nums[i];
                if(myMap.find(complement) != myMap.end())
                {
                    result.push_back(myMap[complement]);
                    result.push_back(i);
                    break;
                }
                myMap[nums[i]] = i;
            }
            return result;
        }
};
