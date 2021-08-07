#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        
        int count = floor(num / 1000);
        num %= 1000;
        for (int i = 0; i < count ; i++)
            ans+= 'M';
        
        count = floor(num / 100);
        num %= 100;
        if (count == 9) {
            ans+= "CM";
            count = 0;
        }
        if (count >= 5) {
            ans+= 'D';
            count -= 5;
        }
        if (count == 4) {
            ans+= "CD";
        }
        else {
            for (int i = 0; i < count ; i++)
                ans += 'C';
        }
        
        count = floor(num/10);
        num %= 10;
        if (count == 9) {
            ans+= "XC";
            count = 0;
        }
        if (count >= 5) {
            ans+= 'L';
            count -= 5;
        }
        if (count == 4) {
            ans+= "XL";
        }
        else {
            for (int i = 0; i < count ; i++)
                ans += 'X';
        }
        
        
        count = num;
        
        if (count == 9) {
            ans+= "IX";
            count = 0;
        }
        if (count >= 5) {
            ans+= 'V';
            count -= 5;
        }
        if (count == 4) {
            ans+= "IV";
        }
        else {
            for (int i = 0; i < count ; i++)
                ans += 'I';
        }
        
        return ans;   
    }
};