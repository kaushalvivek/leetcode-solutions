#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        if (x < 10){
            return true;
        }
        string num = to_string(x);
        int i = 0, j = num.size()-1;
        
        while(j > i){
            if (num[i] != num[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};