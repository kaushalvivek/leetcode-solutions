class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = ['']*numRows
        reverse = False
        curr_row = 0
        forward = True
        for char in s:
            rows[curr_row] += char
            if curr_row == 0:
                forward = True
            if curr_row == len(rows)-1:
                forward = False
            if forward:
                curr_row+=1
            else:
                curr_row-=1
        word = ''
        for row in rows:
            word+=row
        return word