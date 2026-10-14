class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()
        ans = []
        path = []

        def backtrack(start, remaining):
            if remaining == 0:
                ans.append(path.copy())
                return

            for i in range(start, len(candidates)):
                # Skip duplicates at the same recursion level
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                # Since the array is sorted
                if candidates[i] > remaining:
                    break

                path.append(candidates[i])

                # i + 1 means each element is used only once
                backtrack(i + 1, remaining - candidates[i])

                path.pop()

        backtrack(0, target)
        return ans