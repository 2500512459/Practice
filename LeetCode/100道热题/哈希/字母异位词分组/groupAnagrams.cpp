/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]
提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母 
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// 我最开始想到的方法是用一个长度为26的数组来表示一个字符串
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            map<vector<int>, vector<string>> hash;
            for(string str : strs)
            {
                vector<int> key(26, 0);
                for(char c : str)
                {
                    key[c - 'a']++;
                }
                hash[key].push_back(str);
            }
            vector<vector<string>> result;
            for(auto it = hash.begin(); it != hash.end(); it++)
            {
                result.push_back(it->second);
            }
            return result;
        }
 };
// 这个方法比上面的方法要简单很多，因为排序之后，字母异位词就变成了相同的字符串了，所以直接用字符串作为key即可
 class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            map<string, vector<string>> hash;
            for(string str : strs)
            {
                string key = str;
                sort(key.begin(), key.end());
                hash[key].push_back(str);
            }
            vector<vector<string>> result;
            for(auto it = hash.begin(); it != hash.end(); it++)
            {
                result.push_back(it->second);
            }
            return result;
        }
 };