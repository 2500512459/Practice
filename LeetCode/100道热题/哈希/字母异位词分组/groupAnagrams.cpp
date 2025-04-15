/*
����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
��ĸ��λ�� ������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�
ʾ�� 1:
����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
���: [["bat"],["nat","tan"],["ate","eat","tea"]]
ʾ�� 2:
����: strs = [""]
���: [[""]]
ʾ�� 3:
����: strs = ["a"]
���: [["a"]]
��ʾ��
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] ������Сд��ĸ 
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// ���ʼ�뵽�ķ�������һ������Ϊ26����������ʾһ���ַ���
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
// �������������ķ���Ҫ�򵥺ܶ࣬��Ϊ����֮����ĸ��λ�ʾͱ������ͬ���ַ����ˣ�����ֱ�����ַ�����Ϊkey����
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