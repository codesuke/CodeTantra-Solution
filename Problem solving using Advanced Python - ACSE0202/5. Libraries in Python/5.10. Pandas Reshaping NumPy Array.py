import pandas as pd
import numpy as np

# Create a NumPy array
array = np.array([[1, 2, 3, 4],
                 [5, 6, 7, 8],
                 [9, 10, 11, 12]])

# Convert NumPy array to DataFrame
df = pd.DataFrame(array)

# Display the DataFrame
print(df)