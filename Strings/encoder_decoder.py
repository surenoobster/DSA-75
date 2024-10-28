class Solution:
    
    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        
        while i < len(s):
            # Find the next delimiter #
            j = i
            while j < len(s) and s[j] != '#':
                j += 1
            
            # Extract the length of the next string
            length = int(s[i:j])
            i = j + 1
            
            # Extract the actual string based on the length
            str_value = s[i:i + length]
            res.append(str_value)
            
            # Move the index forward by the length of the string just extracted
            i += length
            
        return res
