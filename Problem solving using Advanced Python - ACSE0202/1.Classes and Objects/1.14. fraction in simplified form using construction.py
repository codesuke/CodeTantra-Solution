import math

class Fraction:
    def __init__(self):
        self.num = 0
        self.den = 0
        self.div = 1  # This variable seems to be intended for GCD, not division initially

    def get(self):
        self.num = int(input("Enter numerator:"))
        self.den = int(input("Enter denominator:"))
        if self.den == 0:
            raise ValueError("Denominator cannot be zero.")

    def show(self):
        # Calculate the greatest common divisor to simplify the fraction
        self.div = math.gcd(self.num, self.den)
        # Print the simplified fraction
        print(f"{self.num / self.div:.0f}/{self.den / self.div:.0f}")

# Driver code
frac = Fraction()
frac.get()
frac.show()