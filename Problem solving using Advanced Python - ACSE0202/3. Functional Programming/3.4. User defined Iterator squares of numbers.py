class Squares:
    def __init__(self, limit):
        self.current = 0
        self.limit = limit
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current >= self.limit:
            raise StopIteration
        square = self.current ** 2
        self.current += 1
        return square

# Get user input for the limit
limit = int(input("Enter the limit: "))

# Create the Squares iterator
squares_iter = Squares(limit + 1)

# Print each square up to the limit
for square in squares_iter:
    print(square)