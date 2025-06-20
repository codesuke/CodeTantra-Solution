def fibonacci(limit):
    a, b = 0, 1
    while a <= limit:
        yield a
        a, b = b, a + b

# Get user input for the limit
limit = int(input("Enter-the-limit: "))

# Create the fibonacci sequence generator
fib_gen = fibonacci(limit)

# Print the fibonacci sequence up to the user-specified limit
print("Fibonacci-sequence-up-to-{}: -".format(limit))
for num in fib_gen:
    print("{}".format(num))