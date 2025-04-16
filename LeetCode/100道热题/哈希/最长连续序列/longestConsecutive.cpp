
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
示例 3：
输入：nums = [1,0,1,2]
输出：3
提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//我开始并没有想到使用set，还是想要使用map，后来看了提示才知道
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set(nums.begin(), nums.end());
        int max_len = 0;
    
        for (int num : num_set) {
            // 只有当num是连续序列的起点时（即num-1不在集合中），才进行后续计算
            if (!num_set.count(num - 1)) {
                int current_num = num;
                int current_len = 1;
            
                // 向后查找连续的元素
                while (num_set.count(current_num + 1)) {
                    current_num++;
                    current_len++;
                }   
            
                max_len = max(max_len, current_len);
            }
        }
        return max_len;
    }
};