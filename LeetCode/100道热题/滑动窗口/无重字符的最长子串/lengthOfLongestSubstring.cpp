/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//有问题，可能会出现左边界回退
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> window;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // 出现重复字符时持续收缩左边界（问题点）
            if (window.count(s[right])) {
                left = window[s[right]];//可能导致左边界回退
                window.erase(s[left]);//会导致哈希表记录不完整
            }
            window[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
        
    }
};


class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, -1); // ASCII字符共128个
        int max_len = 0, start = -1; // start相当于左边界
        
        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start) // 仅当重复字符在窗口内时更新
                start = dict[s[i]];
            dict[s[i]] = i;
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
    };