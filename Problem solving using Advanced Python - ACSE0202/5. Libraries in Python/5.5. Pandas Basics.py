import pandas as pd

# 1. Create first DataFrame
data1 = {"Name": ['John', 'Alice', 'Bob'],
         "Age": [25, 28, 22],
         "City": ["New York", 'London', 'Paris']}
df = pd.DataFrame(data1)
print("DataFrame:")
print(df)

# 2. Create second DataFrame
data2 = {"Name": ['Doraemon', 'Nobita', 'Shizuka'],
         "Salary": [10000, 5000, 7500]}
df2 = pd.DataFrame(data2)
print("DataFrame:")
print(df2)

# 3. Filter DataFrames
# Filter df where Age > 23
filtered_df = df[df['Age'] > 23]
print("Filtered DataFrame:")
print(filtered_df)

# Filter df2 where Salary > 5000
filtered_df2 = df2[df2['Salary'] > 5000]
print("Filtered DataFrame:")
print(filtered_df2)

# 4. Basic Statistical Analysis
# For df (Age statistics)
mean_age = df['Age'].mean()
max_age = df['Age'].max()
min_age = df['Age'].min()

print("Mean Age:", mean_age)
print("Maximum Age:", max_age)
print("Minimum Age:", min_age)

# For df2 (Salary average)
avg_salary = df2['Salary'].mean()
print("Average Salary:", avg_salary)