/*
���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ������
�����Ǵ������˳��
ʾ�� 1:
����: s = "cbaebabacd", p = "abc"
���: [0,6]
����:
��ʼ�������� 0 ���Ӵ��� "cba", ���� "abc" ����λ�ʡ�
��ʼ�������� 6 ���Ӵ��� "bac", ���� "abc" ����λ�ʡ�
ʾ�� 2:
����: s = "abab", p = "ab"
���: [0,1,2]
����:
��ʼ�������� 0 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�
��ʼ�������� 1 ���Ӵ��� "ba", ���� "ab" ����λ�ʡ�
��ʼ�������� 2 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�
��ʾ:
1 <= s.length, p.length <= 3 * 104
s �� p ������Сд��ĸ
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
        // Ŀ�괰��
        for(char c : p)
            target[c - 'a']++;
        // ��������
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