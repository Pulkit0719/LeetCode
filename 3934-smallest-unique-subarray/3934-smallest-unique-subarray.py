class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        b1, b2, m1, m2 = 100019, 100043, 10**9+7, 10**9+9
        p1, p2, h1, h2 = [1]*(n+1), [1]*(n+1), [0]*(n+1), [0]*(n+1)

        for i, x in enumerate(nums):
            p1[i+1], p2[i+1] = p1[i]*b1%m1, p2[i]*b2%m2
            h1[i+1], h2[i+1] = (h1[i]*b1+x)%m1, (h2[i]*b2+x)%m2

        def check(k):
            cnt = {}
            for i in range(n-k+1):
                a = (h1[i+k]-h1[i]*p1[k])%m1
                b = (h2[i+k]-h2[i]*p2[k])%m2
                cnt[a,b] = cnt.get((a,b), 0)+1
            return 1 in cnt.values()

        l, r = 1, n
        while l < r:
            mid = (l+r)//2
            if check(mid): r = mid
            else: l = mid+1
        return l