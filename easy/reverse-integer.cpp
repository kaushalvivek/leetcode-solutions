// note : this happens to be the fastest solution for this problem on LeetCode

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int num) {
        if (!num){
            return 0;
        }
        string ans = to_string(num);
        ans = reverseString(ans);
        ans = removeTrailingZeroes(ans);
        ans = handleNegative(ans);
        try
        {
            return stoi(ans);
        }
        catch(...)
        {
            return 0;    
        }
    }
    
    string reverseString(string x)
    {
        string ans;
        for(int i = x.size()-1; i >= 0; i--){
            ans+=x[i];
        }
        return ans;
    }
    
     string removeTrailingZeroes(string num)
     {
        bool nonZeroFound = false;
        string ans = "";
        for(int i = 0; i < num.size(); i++){
            if ((int)num[i] > 0 and !nonZeroFound){
                nonZeroFound = true;
            }
            if (nonZeroFound){
                ans+=num[i];
            }
            else{
                continue;
            }
        }
        return num;
    }
    
    string handleNegative(string ans)
    {
        if (ans[ans.size()-1] == '-'){
            ans.erase(ans.begin()+ans.size()-1);
            ans.insert(0,"-");
        }
        return ans;
    }
};