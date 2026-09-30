class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '#';  // unmatched ')'
                }
            }
        }

        // Remaining '(' are unmatched
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }

        string ans;

        for (char ch : s) {
            if (ch != '#') {
                ans += ch;
            }
        }

        return ans;
    }
};