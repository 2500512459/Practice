/*
����һ���ַ��� s �������ҳ����в������ظ��ַ��� � �Ӵ� �ĳ��ȡ�
ʾ�� 1:
����: s = "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
ʾ�� 2:
����: s = "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
ʾ�� 3:
����: s = "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
��ʾ��
0 <= s.length <= 5 * 104
s ��Ӣ����ĸ�����֡����źͿո����
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//�����⣬���ܻ������߽����
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> window;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // �����ظ��ַ�ʱ����������߽磨����㣩
            if (window.count(s[right])) {
                left = window[s[right]];//���ܵ�����߽����
                window.erase(s[left]);//�ᵼ�¹�ϣ���¼������
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
        vector<int> dict(128, -1); // ASCII�ַ���128��
        int max_len = 0, start = -1; // start�൱����߽�
        
        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start) // �����ظ��ַ��ڴ�����ʱ����
                start = dict[s[i]];
            dict[s[i]] = i;
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
    };