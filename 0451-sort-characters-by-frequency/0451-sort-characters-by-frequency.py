class Solution:
    def frequencySort(self, s: str) -> str:
        # freq hashmap
        freq = Counter(s)
        # reverse the dict acc to its value x[1]
        res = sorted(freq.items(), key=lambda x: x[1], reverse=True) # x[0] means key
        output = ""

        for k, count in res:
            output+= k*count
        return output