
#include<bits/stdc++.h>;

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,vector <int>> m;
        vector<int> results;
        
        for (int i = 0; i < nums.size(); i++){
            
            if (m.find(nums[i]) == m.end()) {
                vector <int> arr;
                arr.push_back(i);
                m.insert(make_pair(nums[i], arr));
            }
            
            else{
                m[nums[i]].push_back(i);
            }
        }
        
        for(int i = 0; i< nums.size(); i++ ){
            
            int to_check = target - nums[i];
            
            if (m.find(to_check) != m.end() && ((to_check != nums[i]) || (to_check == nums[i] && m[to_check].size() > 1))) {        
                    results.push_back(i);
                    results.push_back(m[to_check].back());
                    break;
            }
        }
        return results;
    }
};