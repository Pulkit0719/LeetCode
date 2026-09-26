class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;
        
        // Store knowledge in map
        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }
        
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            
            if (s[i] == '(') {
                string key = "";
                i++;  // move after '('
                
                // Get the key
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                
                // Check if key exists
                if (mp.find(key) != mp.end())
                    ans += mp[key];
                else
                    ans += "?";
            }
            else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};