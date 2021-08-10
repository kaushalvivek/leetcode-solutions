#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int s = nums.size();
        k = k % s;
        
        if (k == 0 or s == 0) { // return when rotation isn't required
            return;
        }
        
        vector<int> newNums;
        
        for (auto i : nums) { // create copy of array
            newNums.push_back(i);
        }
        
        // rotation
        for (int i = 0; i < s; i++) {
            nums[i] = newNums[(i+s-k)%s]; 
        }
        
        return;
    }
};