class Solution:
    def reverse(self, x: int) -> int:
        neg = x < 0
        inStr = str(x)
        if neg:
            inStr = inStr[1:]
        inStr = inStr[::-1]
        if (self.numIsValid(inStr, neg)):
            if neg:
                return -1*int(inStr)
            else:
                return int(inStr)
        else:
            return 0
    
    def numIsValid(self, numInStr, isNeg):
        MAX = 2147483647
        if len(numInStr) == len(str(MAX)):
            for i,char in enumerate(numInStr):
                if i == len(numInStr)-1:
                    if isNeg:
                        return int(char) <= int(str(MAX)[-1])+1
                    return int(char) <= int(str(MAX)[-1])
                if int(char) < int(str(MAX)[i]):
                    return True
                if int(char) > int(str(MAX)[i]):
                    return False
        else:
            return len(numInStr) < len(str(MAX))