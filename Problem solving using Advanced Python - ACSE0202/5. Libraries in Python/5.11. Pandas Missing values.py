import pandas as pd
import numpy as np

# Create the DataFrame with missing values
df = pd.DataFrame({'A': [1, 5, 9],
                   'B': [2, None, 10],
                   'C': [np.nan, 7, 11],
                   'D': [4, 8, np.nan]})

# Count missing values in each column
missing_values = df.isnull().sum()

# Display the count of missing values
print("Pandas - Number of missing values in each column:")
print(missing_values)