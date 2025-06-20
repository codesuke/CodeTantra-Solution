# Get user input for the list of elements
elements = input("Enter a list of elements: ").split()

# Create new list with first letters
new_list = []
for word in elements:
    if word:  # Check if word is not empty
        # Get first alphabetical character if first char is not a letter
        first_char = next((c for c in word if c.isalpha()), '')
        if first_char:
            new_list.append(first_char.lower())

# Print the result
print(new_list)