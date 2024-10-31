class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char in "({[":
                stack.append(char)
            else:
                if len(stack) > 0:  # Check if stack is not empty
                    top = stack[-1]
                    if (char == ')' and top == '(') or (char == '}' and top == '{') or (char == ']' and top == '['):
                        stack.pop()
                    else:
                        return False
                else:
                    return False

        return len(stack) == 0
