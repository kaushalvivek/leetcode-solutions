class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = {}
        for index, val in enumerate(nums):
            if not val in hash_table.keys():
                hash_table[val] = [index]
            else:
                hash_table[val].append(index)
        for val in nums:
            compliment = target-val
            if compliment == val and len(hash_table[val])>=2:
                return hash_table[val][:2]
            if compliment in hash_table.keys() and compliment != val:
                return [hash_table[val][0], hash_table[compliment][0]]
            