class Solution:
    def permute(self, nums):
        ans = []
        current = []
        used = [False] * len(nums)

        def backtrack():
            # Complete permutation
            if len(current) == len(nums):
                ans.append(current.copy())
                return

            for i in range(len(nums)):
                if used[i]:
                    continue

                # Choose
                current.append(nums[i])
                used[i] = True

                # Explore
                backtrack()

                # Backtrack
                current.pop()
                used[i] = False

        backtrack()
        return ans