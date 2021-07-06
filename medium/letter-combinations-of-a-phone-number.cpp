#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector <string> ans = {""};
        unordered_map <char, vector<char>> lettersOf;
        lettersOf['2'] = {'a', 'b', 'c'};
        lettersOf['3'] = {'d', 'e', 'f'};
        lettersOf['4'] = {'g', 'h', 'i'};
        lettersOf['5'] = {'j', 'k', 'l'};
        lettersOf['6'] = {'m', 'n', 'o'};
        lettersOf['7'] = {'p', 'q', 'r', 's'};
        lettersOf['8'] = {'t', 'u', 'v'};
        lettersOf['9'] = {'w', 'x', 'y', 'z'};
        
        for(auto it : digits)
        {   
            vector <string> newAns;
            for (auto ch : lettersOf[it])
            {
                for(auto str : ans)
                {
                    newAns.push_back(str+ch);
                }
            }
            ans = newAns;
        }
        if (ans[0] == "")
        {
            vector <string> empty;
            return empty;
        }
        return ans;
    }
};