
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
        {
            return s.size();
        }
        unordered_map<char, bool> m;
        int n = s.size();
        int i = 0;
        int j = 1;
        m[s[0]] = true;
        int curr_max = 0;
        while (true)
        {
            if (m.find(s[j]) == m.end())
            {
                m[s[j]] = true;
                curr_max = max(j - i + 1, curr_max);
                j++;
            }
            else
            {
                m.erase(s[i]);
                i++;
            }
            if (j == n)
            {
                break;
            }
        }
        return curr_max;
    }
};