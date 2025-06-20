class Person:
    # Constructor with default values
    def __init__(self, name="John Smith", age=35):
        # Write code here
        self.name = name
        self.age = age
        

    # Destructor
    def __del__(self):
        # Complete required code in destructor
        # The destructor is called when an object's reference count becomes zero.
        print(f"{self.name} has been deleted")

# Prompting user to input values for parameterized constructor
name = input("Enter name: ")
age = int(input("Enter age: "))

# Create instances of Person class using default and parameterized constructors

p1 = Person()  # Uses default values ("John Smith", 35)
p2 = Person(name, age) # Uses user-provided values

# Accessing instance variables, write the missing code

print(f"{p1.name} is {p1.age} years old")
print(f"{p2.name} is {p2.age} years old")

# Write code to Delete instances to trigger destructor

del p1
del p2