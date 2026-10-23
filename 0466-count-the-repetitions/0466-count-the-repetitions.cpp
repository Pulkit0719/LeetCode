class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size();
        int len2 = s2.size();

        vector<int> seen(len2 + 1, -1);
        vector<int> count1(n1 + 1, 0);
        vector<int> count2(n1 + 1, 0);

        int j = 0;
        int total2 = 0;

        for (int i = 1; i <= n1; i++) {
            for (char c : s1) {
                if (c == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        total2++;
                    }
                }
            }

            count1[i] = i;
            count2[i] = total2;

            if (seen[j] != -1) {
                int prev = seen[j];

                int preCount = count2[prev];
                int cycleCount = count2[i] - count2[prev];

                int remaining = n1 - prev;
                int cycles = remaining / (i - prev);
                int rest = remaining % (i - prev);

                int result = preCount + cycles * cycleCount;
                result += count2[prev + rest] - count2[prev];

                return result / n2;
            }

            seen[j] = i;
        }

        return total2 / n2;
    }
};