class Circle:
    # Class attribute for PI
    PI = 3.14159

    # Constructor to initialize the radius
    def __init__(self, radius):
        self.radius = radius

    # Method to calculate the area
    def area(self):
        return Circle.PI * self.radius ** 2

    # Method to calculate the circumference
    def circum(self):
        return 2 * Circle.PI * self.radius

# Get radius from user input and convert it to an integer
radius = int(input("Enter radius: "))

# Create an instance of the Circle class
c1 = Circle(radius)

# Print the attributes and method results of the instance
print("Radius:", c1.radius)
print("Area:", c1.area())
print("Circumference:", c1.circum())