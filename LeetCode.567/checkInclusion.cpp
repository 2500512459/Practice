/*
题目选择：567. 字符串的排列

题目描述：
给定两个字符串 s1 和 s2，判断 s2 是否包含 s1 的任意排列的子串。
即，若 s1 的排列之一是 s2 的子串，返回 true；否则返回 false。

示例：
输入：s1 = "ab", s2 = "eidbaooo"
输出：true
解释：s2 包含 "ba"（s1 的排列之一）
*/

#include <map>
using namespace std;

//第一次解题(找出s2 中所有长度等于 s1 的子串然后进行比较)
bool checkInclusion_1(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	if (n > m) return false;

	// s1字符
	map<char, int> target;
	for (char c : s1) {
		target[c]++;
	}

	// 遍历所有可能子串
	for (int i = 0; i <= m - n; ++i) {
		map<char, int> current;
		// 统计当前子串字符
		for (int z = i; z < i + n; ++z) {
			char c = s2[z];
			current[c]++;
		}
		// 直接比较map
		if (current == target) {
			return true;
		}
	}
	return false;
}

//在阅读完正确答案解题思路后，发现需要用到滑动窗口，并且因为字母只有26个的原因可以使用vector
bool checkInclusion_2(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();
	if (n > m) return false;

	vector<int> target(26, 0);
	for (char c : s1)
	{
		target[c - 'a']++;
	}

	vector<int> window(26, 0);
	for (int i = 0; i < n; i++)
	{
		window[s2[i] - 'a']++;
	}

	for (int i = n; i < m; i++)
	{
		window[s2[i - n] - 'a']--;
		window[s2[i] - 'a']++;
		if (target == window)
			return true;
	}
	return false;
}

//还是不对，正确答案还需要差异计数器

//正确答案：
bool checkInclusion(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	if (n > m) return false;

	vector<int> target(26, 0), window(26, 0);
	for (char c : s1) target[c - 'a']++;

	// 初始化窗口
	for (int i = 0; i < n; ++i) {
		window[s2[i] - 'a']++;
	}

	int diff = 0;
	for (int i = 0; i < 26; ++i) {
		if (window[i] != target[i]) diff++;
	}
	if (diff == 0) return true;

	// 滑动窗口
	for (int i = n; i < m; ++i) {
		int left = s2[i - n] - 'a';
		int right = s2[i] - 'a';

		// 更新左边界
		if (window[left] == target[left]) diff++;
		window[left]--;
		if (window[left] == target[left]) diff--;

		// 更新右边界
		if (window[right] == target[right]) diff++;
		window[right]++;
		if (window[right] == target[right]) diff--;

		if (diff == 0) return true;
	}
	return false;
}