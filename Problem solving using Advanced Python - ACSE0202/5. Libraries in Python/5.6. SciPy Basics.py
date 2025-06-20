from scipy.special import factorial
import numpy as np
from scipy.linalg import solve, inv
from scipy.integrate import quad

# 1. Factorial calculations with proper spacing
print("Factorial of 5 is:", factorial(5))
print("Factorial of 50 is:", factorial(50))

# 2. Linear equation solving
A = np.array([[2, 3], [4, -1]])
b = np.array([9, 5])
x = solve(A, b)
print("Solution:")
print("x =", x[0])
print("y =", x[1])

# 3. Matrix inversion with proper formatting
A_inv = inv(A)
print(f"Inverse of square matrix A is [[ {A_inv[0,0]:.8f} {A_inv[0,1]:.8f}]")
print(f" [ {A_inv[1,0]:.8f}.{A_inv[1,1]:.8f}]]")

# 4. Numerical integration
def f(x):
    return x**2

result1, _ = quad(f, 0, 2)
print("Numerical Integration Result:", result1)
result2, _ = quad(f, 1, 10)
print("Numerical Integration Result:", result2)