class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        string result = "";

        // Build the result in decreasing frequency order
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            result += string(count, ch);
        }

        return result;
    }
};