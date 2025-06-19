import numpy as np
from scipy.sparse import csr_matrix

# Get user input for the size of the matrix
size = int(input("Enter the size of the matrix: "))

# Create a 2-D array with ones on the diagonal and zeros elsewhere
arr = np.eye(size)

# Convert the NumPy array to a SciPy sparse matrix in CSR format
sparse_mat = csr_matrix(arr)

# Display the original array
print("Original array:")
print(arr)

# Display the sparse matrix in CSR format
print("Sparse matrix in CSR format:")
print(sparse_mat)