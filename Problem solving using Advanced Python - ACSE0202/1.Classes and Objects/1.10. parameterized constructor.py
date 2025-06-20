import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def midpoint(self, other):
        mid_x = (self.x + other.x) / 2
        mid_y = (self.y + other.y) / 2
        return (mid_x, mid_y)

    def length(self, other):
        return math.sqrt(((self.x - other.x)**2) + ((self.y - other.y)**2))

x1 = int(input("Enter x1 value:"))
y1 = int(input("Enter y1 value:"))
x2 = int(input("Enter x2 value:"))
y2 = int(input("Enter y2 value:"))

p1 = Point(x1, y1)
p2 = Point(x2, y2)

print(f'Midpoint: {p1.midpoint(p2)}')
print(f"Length: {p1.length(p2):.2f}")