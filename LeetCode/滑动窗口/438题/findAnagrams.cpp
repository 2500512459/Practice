#include <vector>
#include <map>
using namespace std;

/*
题目选择：438. 找到字符串中所有字母异位词

题目描述：
给定两个字符串 s 和 p，找到 s 中所有 p 的 字母异位词 的子串，返回这些子串的起始索引。
字母异位词指字母相同但排列不同的字符串。

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释: 起始索引 0 的子串 "cba" 是 "abc" 的异位词，索引 6 的子串 "bac" 也是异位词。
*/

//同567题类似，每次移动滑动窗口和目标判断一下就行
vector<int> findAnagrams(string s, string p)
{
	vector<int> value;
	if (s.size() < p.size())
		return value;

	vector<int> target(26, 0);//目标
	vector<int> window(26, 0);//滑动窗口

	//获取目标
	for (char c : p)
	{
		target[c - 'a']++;
	}
	//初始化窗口
	for (int i = 0; i < p.size(); ++i)
	{
		window[s[i] - 'a']++;
	}

	if (target == window)
		value.push_back(0);

	for (int i = p.size(); i < s.size(); i++)
	{
		window[s[i - p.size()] - 'a']--;
		window[s[i] - 'a']++;
		if (window == target)
			value.push_back(i - p.size() + 1);
	}
	return value;
}