class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        // Count characters in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Use characters to construct ransomNote
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0) {
                return false;
            }

            freq[c - 'a']--;
        }

        return true;
    }
};