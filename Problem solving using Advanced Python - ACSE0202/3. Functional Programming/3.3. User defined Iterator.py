class EvenNumbers:
    def __init__(self, limit):
        self.current = 0
        self.limit = limit
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current > self.limit:
            raise StopIteration
        even_num = self.current
        self.current += 2
        return even_num

# Get user input for the limit value
limit = int(input("Enter-the-limit: "))

# Create an EvenNumbers iterator object
even_iter = EvenNumbers(limit)

# Iterate and print each even number
for num in even_iter:
    print(num)