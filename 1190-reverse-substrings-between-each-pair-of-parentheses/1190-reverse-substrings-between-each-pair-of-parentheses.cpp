class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<string> st;
        string curr = "";
        
        for (char ch : s) {
            
            if (ch == '(') {
                // Save the current string
                st.push(curr);
                curr = "";
            }
            else if (ch == ')') {
                // Reverse the string inside brackets
                reverse(curr.begin(), curr.end());
                
                // Add it to the previous string
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += ch;
            }
        }
        
        return curr;
    }
};