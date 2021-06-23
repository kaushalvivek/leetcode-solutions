#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        vector<string> words;
        int i = 0;
        while(i < numRows) {
            words.push_back("");
            i++;
        }
        int curr = 0;
        bool forward = true;
        for(int i = 0; i < s.size(); i++)
        {
            words[curr]+=s[i];
            if (curr == 0)
            {
                forward = true;
            }
            if (curr == numRows-1)
            {
                forward = false;
            }
            if (forward)
            {
                curr++;
            }
            else
            {
                curr--;
            }
        }
        string ans;
        for(int i = 0; i< numRows; i++)
        {
            ans+=words[i];
        }
        return ans;
    }
};