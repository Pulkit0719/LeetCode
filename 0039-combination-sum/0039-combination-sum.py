class Solution:
    def combinationSum(self, candidates, target):
        result = []

        def backtrack(index, target, current):
            if target == 0:
                result.append(current[:])
                return

            if index >= len(candidates) or target < 0:
                return

            # Take current element
            if candidates[index] <= target:
                current.append(candidates[index])

                # Same index because we can reuse the element
                backtrack(index, target - candidates[index], current)

                current.pop()

            # Skip current element
            backtrack(index + 1, target, current)

        backtrack(0, target, [])

        return result