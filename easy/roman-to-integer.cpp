#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'I':
                    if (i < s.size()-1)
                    {
                        if (s[i+1] == 'V')
                        {
                            ans+=4;
                            i++;
                            break;
                        }    
                        else if (s[i+1] == 'X') 
                        {
                            ans+=9;
                            i++;
                            break;
                        }   
                    }
                    ans += val[s[i]];
                    break;
                case 'C':
                    if (i < s.size()-1)
                    {
                        if (s[i+1] == 'D')
                        {
                            ans+=400;
                            i++;
                            break;
                        }    
                        else if (s[i+1] == 'M') 
                        {
                            ans+=900;
                            i++;
                            break;
                        }   
                    }
                    ans += val[s[i]];
                    break;
                case 'X':
                    if (i < s.size()-1)
                    {
                        if (s[i+1] == 'L')
                        {
                            ans+=40;
                            i++;
                            break;
                        }    
                        else if (s[i+1] == 'C') 
                        {
                            ans+=90;
                            i++;
                            break;
                        }   
                    }
                    ans += val[s[i]];
                    break;
                default:
                    ans += val[s[i]];
            }
        }
        return ans;
    }
};