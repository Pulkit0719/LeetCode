class Solution {
public:
    static const long long MOD1 = 1000000007;
    static const long long MOD2 = 1000000009;
    static const long long BASE = 911382323;

    vector<long long> h1, h2, p1, p2;

    void preprocess(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;
        }
    }

    uint64_t getHash(int l, int r) {
        int len = r - l + 1;

        long long a = (h1[r + 1] - h1[l] * p1[len] % MOD1 + MOD1) % MOD1;
        long long b = (h2[r + 1] - h2[l] * p2[len] % MOD2 + MOD2) % MOD2;

        return (uint64_t(a) << 32) | uint64_t(b);
    }

    bool check(int len, int n) {
        unordered_map<uint64_t, int> freq;
        freq.reserve(n);
        freq.max_load_factor(0.7);

        for (int i = 0; i + len <= n; i++) {
            uint64_t h = getHash(i, i + len - 1);
            freq[h]++;
        }

        for (auto& [hash, count] : freq) {
            if (count == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        preprocess(nums);

        int lo = 1, hi = n, ans = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};