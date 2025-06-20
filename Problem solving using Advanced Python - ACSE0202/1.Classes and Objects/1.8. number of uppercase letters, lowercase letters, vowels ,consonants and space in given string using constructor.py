class String:
    def __init__(self, string):
        self.string = string
        self.upper = 0
        self.lower = 0
        self.con = 0
        self.vowel = 0
        self.space = 0

    def count(self):
        vowel_set = set("AEIOUaeiou")
        for char in self.string:
            if char.isupper():
                self.upper += 1
            if char.islower():
                self.lower += 1
            if char in vowel_set:
                self.vowel += 1
            elif char.isalpha():
                self.con += 1
            if char.isspace():
                self.space += 1

    def display(self):
        print(f'String: {self.string}')
        print(f'Uppercase letters: {self.upper}')
        print(f'Lowercase letters: {self.lower}')
        print(f'Vowels: {self.vowel}')
        print(f'Consonants: {self.con}')
        print(f'Spaces: {self.space}')


# Driver code
str_input = input("Enter string: ")
s1 = String(str_input)
s1.count()
s1.display()
