class Car:
    # Class attribute
    num_wheels = 4

    # Constructor method
    def __init__(self, make, model, year):
        # Define the constructor and initialize instance attributes
        self.make = make
        self.model = model
        self.year = year

    # Instance method
    def start(self):
        # Complete this instance method
        print(f"The {self.year} {self.make} {self.model} is starting up...")

# Get user input
make = input("Enter make: ")
model = input("Enter model: ")
year = int(input("Enter year: "))

# Create an instance of the Car class
my_car = Car(make, model, year)
# acess instance variable
print(f"My car is a {my_car.make} {my_car.model} from {my_car.year}")

# You can also access attributes directly
print(f"This car has {my_car.num_wheels} wheels.")
# Call the start method on the instance
my_car.start()