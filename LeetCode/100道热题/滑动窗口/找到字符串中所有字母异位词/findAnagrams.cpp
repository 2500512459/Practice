/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。
不考虑答案输出的顺序。
示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
提示:
1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> window(26, 0), target(26, 0);
        // 目标窗口
        for(char c : p)
            target[c - 'a']++;
        // 滑动窗口
        for(int i = 0; i < p.size(); i++)
        {
            window[s[i] - 'a']++;
        }
        if (window == target)
            res.push_back(0);
        
        for(int i = p.size(); i < s.size(); i++)
        {
            window[s[i] - 'a']++;
            window[s[i - p.size()] - 'a']--;
            if(window == target)
                res.push_back(i - p.size() + 1);
        }

        return res;
    }
};