import pandas as pd

# Given the series are already provided as per the problem statement
# For demonstration, I'll create them based on the test case
s1 = pd.Series([6, 7, 8, 9, 10])
s2 = pd.Series([1, 2, 3, 4, 5])

# Element-wise operations
addition = s1 + s2
subtraction = s1 - s2
multiplication = s1 * s2
division = s1 / s2

# Display results
print("Addition:")
print(addition)
print("Subtraction:")
print(subtraction)
print("Multiplication:")
print(multiplication)
print("Division:")
print(division)
