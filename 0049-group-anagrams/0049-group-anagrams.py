class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # empty dic banao
        groups = {}
        # sorted key banao 
        for word in strs:
            key = ''.join(sorted(word))
            # agar key hai toh bhadia warna add it as new key
            if key not in groups:
                groups[key] = []
            # current word ko currr key ke hisab se add kardo
            groups[key].append(word)

        return list(groups.values())