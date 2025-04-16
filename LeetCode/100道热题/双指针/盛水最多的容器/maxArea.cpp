/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。
示例 1：
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水的最大值为 49。
示例 2：
输入：height = [1,1]
输出：1
提示：
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 我只想到了 暴力法，时间复杂度O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int area = (j - i) * min(height[i], height[j]);
                maxArea = max(maxArea, area);
            }
        }
    }
};
// 解答为双指针法，时间复杂度O(n)
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int max_area = 0;
            int left = 0;
            int right = height.size() - 1;
            
            while (left < right) {
                int current_height = min(height[left], height[right]);
                int current_width = right - left;
                max_area = max(max_area, current_height * current_width);
                
                // 移动较短边的指针以寻找更大高度
                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            
            return max_area; // 原代码缺少返回语句
        }
    };