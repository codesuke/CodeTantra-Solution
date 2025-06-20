import numpy as np

# Define the matrices
matrix1 = np.array([[1, 2, 3],
                   [4, 5, 6],
                   [7, 8, 9]])
matrix2 = np.array([[10, 11],
                   [12, 13],
                   [14, 15]])

# Perform matrix multiplication
result = np.matmul(matrix1, matrix2)  # or use matrix1 @ matrix2

# Display the result
print(result)