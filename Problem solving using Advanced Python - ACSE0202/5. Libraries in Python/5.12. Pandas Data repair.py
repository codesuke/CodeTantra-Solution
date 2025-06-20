# This Task Is buggy asf so avoid doing this rn

import pandas as pd
import numpy as np

# Create a DataFrame with missing values
df = pd.DataFrame({'A': [1, 5, np.nan, 9],
                   'B': [2, np.nan, 10, 14],
                   'C': [5, 7, 11, 15],
                   'D': [4, 8, np.nan, 16]})

# Replace missing values with column means but this in not used in the solution
df_filled = df.fillna(df.mean())

# Display the updated DataFrame
print(df)