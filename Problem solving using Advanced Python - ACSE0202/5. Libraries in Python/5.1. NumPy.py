import numpy as np


def calculate_max_min_diff(arr):
    # Calculate max along axis 1 (rows)
    max_values = np.max(arr, axis=1)
    # Calculate min along axis 1 (rows)
    min_values = np.min(arr, axis=1)
    # Calculate difference
    diff = max_values - min_values
    return diff


# For the sample test case shown in the image (though it's incomplete):
arr = np.array([[4, 5, 2],
                [9, 3, 7],
                [1, 6, 8]])

diff = calculate_max_min_diff(arr)
print(diff)
