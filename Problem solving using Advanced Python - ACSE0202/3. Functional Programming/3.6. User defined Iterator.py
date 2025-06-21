# Get user input for the list of elements
existing_list = input("Enter a list of elements: ")
existing_list = existing_list.split(" ")

# Create new list with first letters
new_list = map(lambda x: x[0], existing_list)
new_list = list(new_list)

# Print the result
print(new_list)