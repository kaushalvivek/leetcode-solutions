#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector <vector <int>> dp;
        vector <int> row;
        for (int i = 0; i < s.size(); i++){
            row.push_back(0);        
        }
        for (int i = 0; i < s.size(); i++){
            dp.push_back(row);
        }
        int start = 0;
        int span = 0;
        
        // all elements are palindromes of themselves
        for (int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        
        // two letters are palindromes if equal
        for (int i = 0; i < s.size()-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                span = 1;
            }
        }
        
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 0; j < s.size()-1; j++)
            {
                if (dp[i-1][j+1] == 1 and s[i] == s[j])
                {
                    dp[i][j] = 1;
                    if (abs(i-j) > span){
                        start = min(i,j);
                        span = abs(i-j);
                    }
                }    
            }
        }
        return s.substr(start, span+1);
    }
};