class Complex:
    def __init__(self):
        self.x = 0
        self.y = 0

    def read(self, other):
        self.x = int(input("Enter the real part of the first complex number: "))
        self.y = int(input("Enter the imaginary part of the first complex number: "))
        other.x = int(input("Enter the real part of the second complex number: "))
        other.y = int(input("Enter the imaginary part of the second complex number: "))

    def display(self, other):
        print("First complex number:")
        print(f"{self.x:.1f} + {self.y:.1f}i")
        print("Second complex number:")
        print(f"{other.x:.1f} + {other.y:.1f}i")

    def add(self, other):
        print("Sum of the two complex numbers:")
        print(f"{self.x + other.x:.1f} + {self.y + other.y:.1f}i")

    def sub(self, other):
        print("Difference of the two complex numbers:")
        print(f"{self.x - other.x:.1f} + {self.y - other.y:.1f}i")

# Driver code
c1 = Complex()
c2 = Complex()

while True:
    print("\nSelect an option:")
    print("1. Read two complex numbers")
    print("2. Display two complex numbers")
    print("3. Add two complex numbers")
    print("4. Subtract two complex numbers")
    print("5. Exit")

    n = int(input("Enter your choice: "))

    if n == 1:
        c1.read(c2)
    elif n == 2:
        c1.display(c2)
    elif n == 3:
        c1.add(c2)
    elif n == 4:
        c1.sub(c2)
    elif n == 5:
        break
    else:
        print("Invalid choice. Please try again.")