from functools import reduce

# Get user input for N
N = int(input("N: "))

# Calculate sum using reduce
numbers = range(1, N+1)
sum_result = reduce(lambda x, y: x + y, numbers)

# Print the result
print("Sum:", sum_result)