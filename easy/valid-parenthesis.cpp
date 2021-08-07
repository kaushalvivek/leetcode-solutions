#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        list <char> st;
        unordered_map <char, char> openOf;
        openOf[')'] = '(';
        openOf['}'] = '{';
        openOf[']'] = '[';
        
        for (char a : s) {
            
            // it's an open bracket
            if (a == '(' or a == '[' or a == '{') {
                st.push_front(a);
            }
            
            else {
                
                // no open brackets in stack
                if (st.empty()) {
                    return false;
                }
                
                char top = st.front();
                
                if (top == openOf[a]) // bracket match
                    st.pop_front();
                
                else                 // mismatch
                    return false;
            }
        }
        
        
        return (st.empty());
    }
};