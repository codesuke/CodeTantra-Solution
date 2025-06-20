class Student:
    def __init__(self,name,sub1,sub2,sub3):
        self.name =name
        self.sub1 =sub1
        self.sub2 =sub2
        self.sub3 =sub3
        self.marks =[]
        self.total_marks = 0.0
        self.avg_marks =0.0
    def compute(self):
        self.marks =[self.sub1, self.sub2, self.sub3]
        self.total_marks = self.sub1+self.sub2+self.sub3
        self.avg_marks = self.total_marks/3
    def display(self):
        print(f"Name: {self.name}")
        print(f"Marks: {self.marks}")
        print(f"Total_Marks: {self.total_marks}")
        print(f"Average Marks: {self.avg_marks}")

# Create a student object
name = input("Student name: ")
print ("Enter marks: ")
s1 =int(input())
s2 =int(input())
s3 =int(input())
student1 =Student(name,s1,s2,s3)
student1.compute()
student1.display()