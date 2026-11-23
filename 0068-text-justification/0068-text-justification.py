
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        n = len(words)
        i = 0

        while i < n:
            j = i
            letters = 0

            # Find maximum words that fit in this line
            while j < n and letters + len(words[j]) + (j - i) <= maxWidth:
                letters += len(words[j])
                j += 1

            gaps = j - i - 1

            # Last line or single word
            if j == n or gaps == 0:
                line = " ".join(words[i:j])
                res.append(line + " " * (maxWidth - len(line)))

            else:
                total_spaces = maxWidth - letters
                spaces, extra = divmod(total_spaces, gaps)

                line = ""

                for k in range(i, j - 1):
                    line += words[k]
                    line += " " * (spaces + (1 if k - i < extra else 0))

                line += words[j - 1]
                res.append(line)

            i = j

        return res
