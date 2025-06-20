class Numbers:
    num = []

    def insert_element(self):
        n = int(input("Enter a number: "))
        Numbers.num.append(n)

    def max_num(self):
        maximum = max(Numbers.num)
        print(f"The largest number is: {maximum}")


# Driver code
n = int(input("Enter number of elements: "))
num1 = Numbers()

for _ in range(n):
    num1.insert_element()

num1.max_num()
