class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        visited = []
        visited.append(s[0])
        curr_max = 1
        i = 0
        j = 1
        while True:
            if s[j] in visited:
                visited.remove(s[i])
                i+=1
            else:
                visited.append(s[j])
                curr_max = max(curr_max, j-i+1)
                j+=1
            if j == len(s):
                return curr_max
        