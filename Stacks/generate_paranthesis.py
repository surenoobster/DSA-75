from typing import List

class ParenthesisGenerator:
    def __init__(self, n: int):
        self.n = n          # Number of pairs of parentheses
        self.result = []    # To store the valid combinations

    def generate(self) -> List[str]:
        self.helper(0, 0, "")
        return self.result

    def helper(self, open_count: int, close_count: int, current_string: str):
        # Base case: if we have used n open and n close parentheses
        if open_count == self.n and close_count == self.n:
            self.result.append(current_string)
            return
        
        # If we can still add an open parenthesis
        if open_count < self.n:
            self.helper(open_count + 1, close_count, current_string + "(")
        
        # If we can add a close parenthesis
        if close_count < open_count:
            self.helper(open_count, close_count + 1, current_string + ")")

# Example usage
generator = ParenthesisGenerator(3)
print(generator.generate())  # Output: ["((()))", "(()())", "(())()", "()()()"]
