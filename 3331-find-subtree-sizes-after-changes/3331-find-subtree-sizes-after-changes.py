
class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)

        adj = [[] for _ in range(n)]

        for i in range(1, n):
            adj[parent[i]].append(i)

        newParent = [-1] * n
        last = [-1] * 26

        def dfs(node):
            ch = ord(s[node]) - ord('a')

            previous = last[ch]

            if node == 0:
                newParent[node] = -1
            elif previous != -1:
                newParent[node] = previous
            else:
                newParent[node] = parent[node]

            last[ch] = node

            for child in adj[node]:
                dfs(child)

            last[ch] = previous

        dfs(0)

        newAdj = [[] for _ in range(n)]

        for i in range(1, n):
            newAdj[newParent[i]].append(i)

        ans = [1] * n

        def calculate(node):
            for child in newAdj[node]:
                ans[node] += calculate(child)

            return ans[node]

        calculate(0)

        return ans
