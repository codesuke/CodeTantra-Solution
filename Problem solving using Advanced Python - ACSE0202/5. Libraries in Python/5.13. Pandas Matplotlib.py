import pandas as pd
import matplotlib.pyplot as plt
from pyodide.http import open_url

url = 'https://ct-public-bucket.s3.ap-south-1.amazonaws.com/lms/niet/alphabet_stock_data.csv'
csv_data = open_url(url)
df = pd.read_csv(csv_data)

# Convert the 'Date' column to datetime format
df['Date'] = pd.to_datetime(df['Date'])

# Set the 'Date' column as the index of the DataFrame
df.set_index('Date', inplace=True)

# Create a figure with a specified size of 12x6 inches
plt.figure(figsize=(12, 6))

# Plot the 'Open' column (opening stock prices) with a label 'Opening Price'
df['Open'].plot(label='Opening Price')

# Plot the 'Close' column (closing stock prices) with a label 'Closing Price'
df['Close'].plot(label='Closing Price')

# Add a title to the plot
plt.title("Alphabet Inc. Stock Prices")

# Label the X-axis as 'Date'
plt.xlabel("Date")

# Label the Y-axis as 'Price'
plt.ylabel("Price")

# Add a legend
plt.legend()

# Display the plot
plt.show()