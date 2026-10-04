class Solution:
    def checkValidString(self, s: str) -> bool:
        minOpen = 0
        maxOpen = 0

        for ch in s:
            if ch == '(':
                minOpen += 1
                maxOpen += 1

            elif ch == ')':
                minOpen -= 1
                maxOpen -= 1

            else:  # '*'
                minOpen -= 1  # '*' acts as ')'
                maxOpen += 1  # '*' acts as '('

            # Too many closing brackets
            if maxOpen < 0:
                return False

            # Minimum cannot be negative
            minOpen = max(0, minOpen)

        return minOpen == 0