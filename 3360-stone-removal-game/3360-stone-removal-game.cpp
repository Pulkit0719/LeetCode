class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;
        bool alice = true;

        while (n >= k) {
            n -= k--;
            alice = !alice;
        }

        return !alice;
    }
};