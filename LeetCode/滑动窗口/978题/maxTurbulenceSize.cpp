#include <vector>
#include <algorithm>
using namespace std;
/*
978题，题目：最长湍流子数组 给定一个整数数组 arr，返回 arr 的 最大湍流子数组的长度。

当满足以下条件时，我们称子数组 arr[i...j] 为湍流子数组：

对于 i <= k < j：
如果 k 为奇数，那么 arr[k] > arr[k+1]
如果 k 为偶数，那么 arr[k] < arr[k+1] 或者
对于 i <= k < j：
如果 k 为奇数，那么 arr[k] < arr[k+1]
如果 k 为偶数，那么 arr[k] > arr[k+1]
（即该子数组的相邻元素交替呈现严格递增和严格递减的特性）

示例 1
输入：arr = [9,4,2,10,7,8,8,1,9]
输出：5
解释：最长的湍流子数组是 [4,2,10,7,8]，长度为 5
示例 2：
输入：arr = [4,8,12,16]
输出：2
解释：可以是 [4,8] 或 [8,12] 等，长度均为 2
*/
vector<int> maxTurbulenceSize(vector<int>& arr) {
    if (arr.size() == 1) return 1;
    
    int max_len = 1;
    int left = 0;
    int right = 0;
    vector<int>& arr_max;
    for(init i = 0; i < arr.size(); ++i)
    {
        if (left == right) {
            // 处理每次移动左窗口时和右窗口在一起的情况
            if (arr[right] == arr[right + 1]) left++; // 相等则同步右移
            right++;
        } 
        else
        {
            //只要当前右窗口所在的元素是湍流元素，则右窗口右移
            if((arr[right-1] < arr[right] && arr[right] > arr[right+1]) || 
            (arr[right-1] > arr[right] && arr[right] < arr[right+1])) 
            {
                right++;
            }
            else
            {
                left = right;
            }
        } 
        max_len = max(max_len, right - left + 1);
    }
    for(int i = left; i < right; ++i)
    {
        arr_max.push_back(arr[i]);
    }
    
    return arr_max;
}