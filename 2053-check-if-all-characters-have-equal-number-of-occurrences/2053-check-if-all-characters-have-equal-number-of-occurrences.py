class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        x=Counter(s)
        mx=-inf
        mi=inf
        for i in x:
            mx=max(mx,x[i])
            mi=min(mi,x[i])
        return mx==mi