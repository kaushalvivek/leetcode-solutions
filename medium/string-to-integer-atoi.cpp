#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    
    // keep the number within limits
    int validate(long int num, long int val, bool isNeg) {
        if (!isNeg)
            return num + val > INT_MAX ? INT_MAX : num + val;
        else
            return num-val < INT_MIN ? INT_MIN : num-val;
    }
    
    
    // check if char is a digit
    bool isDigit (char c) {
        int val = c -'0';
        return (val >= 0 and val <= 9);
    }
    
    // return valid digits to evaluate in string
    string getDigits(string s) {
        string ans = "";
        bool nonZeroFound = false;
        int ind = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-' or s[i] == '+') {
                if (i == 0)
                    continue;
                else
                    return ans;
            } 
            if (s[i] == '0' and !nonZeroFound) continue; // trim prefixed 0s
            if (!isDigit(s[i])) // return on encountering non-digit 
                return ans;
            ans+=s[i];
            nonZeroFound = true;
        }
        return ans;
    }
    
    // trim leading spaces
    string trimSpace(string s) {
        string ans = "";
        bool nonSpaceFound = false;
        for (auto i : s) {
            if (i == ' ' and !nonSpaceFound) continue;
            ans+=i;
            nonSpaceFound = true;
        }
        return ans;
    }
    
    // return integer
    int getInt(string s, bool isNeg) {
        int ans = 0;
        int e = 0;
        int digit;
        int digVal = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            digit = s[i]-'0';
            digVal = digit*pow(10,e) > INT_MAX? INT_MAX : digit*pow(10, e);
            ans = validate(ans, digVal, isNeg);
            e++;
        }
        return ans;
    }
    
    int myAtoi(string s) {
        s = trimSpace(s);
        bool isNeg = (s[0] == '-');
        string num = getDigits(s);
        int ans = 0;
        if (num.size() > 0)
            ans = getInt(num, isNeg);
        return ans;   
    }
};