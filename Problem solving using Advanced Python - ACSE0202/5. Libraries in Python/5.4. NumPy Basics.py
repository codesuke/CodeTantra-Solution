import numpy as np

# 1. Sum of array elements
numbers1 = np.array([1, 2, 3, 4, 5])
sum_of_elements = np.sum(numbers1)
print("The sum of array elements is:", sum_of_elements)

numbers2 = np.array([1, 2, 3, 4, 5])
sum_of_elements = np.sum(numbers2)
print("The sum of array elements is:", sum_of_elements)

# 2. Matrix multiplication
matrix1 = np.array([[1, 2, 3], [4, 5, 6]])
matrix2 = np.array([[7, 8], [9, 10], [11, 12]])
result = np.dot(matrix1, matrix2)
print(result)

matrix3 = np.array([[11, 22, 33], [44, 55, 66]])
matrix4 = np.array([[77, 88], [99, 100], [111, 122]])
result = np.dot(matrix3, matrix4)
print(result)

# 3. Element-wise operations
numbers3 = np.array([1, 2, 3, 4, 5])
squared = np.square(numbers3)
cubed = np.power(numbers3, 3)
print("Squared array:")
print(squared)
print("Cubed array:")
print(cubed)

numbers4 = np.array([11, 22, 33, 44, 55, 66])
sqrt_array = np.sqrt(numbers4)
print("Sqrt of array:")
print(sqrt_array)

# 4. Array reshaping
numbers6 = np.array([1, 2, 3, 4, 5, 6])
matrix = numbers6.reshape(2, 3)
print("Reshaped matrix:")
print(matrix)

# Reshape to 2xN (automatic calculation of N)
reshaped = numbers6.reshape(2, -1)
print("Reshaped matrix:")
print(reshaped)