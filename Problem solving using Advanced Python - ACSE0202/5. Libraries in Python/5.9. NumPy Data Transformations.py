import pandas as pd
import numpy as np

# Create a Series from a list
list_data = ['a', 'b', 'c', 'd']
series_from_list = pd.Series(list_data)
print("Series from list:")
print(series_from_list)

# Create a Series from a NumPy array
array_data = np.array([10, 20, 30, 40])
series_from_array = pd.Series(array_data)
print("Series from NumPy array:")
print(series_from_array)

# Create a Series from a dictionary
dict_data = {'A': 100, 'B': 200, 'C': 300, 'D': 400}
series_from_dict = pd.Series(dict_data)
print("Series from dictionary:")
print(series_from_dict)