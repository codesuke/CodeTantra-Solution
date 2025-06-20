def count_up_to_ten():
    counter = 0
    while True:
        if counter == 10:
            raise Exception("Counter has reached 10°")
        yield counter
        counter += 1

# Create the count up to ten generator
generator = count_up_to_ten()

try:
    # Print each number in the sequence up to 9
    for num in generator:
        print(num)
except Exception as e:
    # Print message raised by Exception
    print(e)