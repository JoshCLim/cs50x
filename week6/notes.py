'''

-----     LECTURES     -----

procedural programming



indentation in python is important

data types:
    bool        booleans
    float       floats
    int         integers
    str         strings

    range
    list        lists           basically arrays
    tuple       tuples          e.g. (x, y)
    dict        objects         unordered list of keys and values
    set


python and the command line 
    python hello.py

python is "interpreted" not "compiled"

python is slower than C coz it's interpreted


traceback   =    traceback through all the functions that were executed; gives line number of error


concatenation = where two strings are "added" / "joined" together


type casting in python
    int()
    str()
    float()


you no longer need to convert to float like in C; python does not 'truncate'
    /       divides (can output a float)
    //      divides and truncates

floating point imprecision still exists in python


python has no data type for 'char' - they are all strings

in python, the words 'or' and 'and' work as logical operators

the operator 'in' checks if a value is in a list



a string in python is "immutable" - you cannot change it / go into memory an change it



it is a convention of python to use a "main()" function
    but remember to call it!

    or 

    if __name__ == "__main__":
        main()


    define global variables outside the main function



python has no pointers, addresses, malloc etc.




a variable in python will exist inside of the whole function (e.g. outside of loops etc, unlike in C)




documentation - can help us find functions etc. that can be useful


method = a function "built into" an object



to use command line arguments, you need to import argv from sys
    from sys import argv



foo, bar, baz = common placeholder variable names
'''

# print hello world
print("hello, world")



# get input and print hello, [name]
answer = input("What's your name? ")

print("hello, " + answer)
    # OR
print(f"hello, {answer}")



# declare integer variable
counter = 0

# increase counter by 1
counter = counter + 1
    # OR
counter += 1



# if, elif, else statement
x, y = 0, 1

if (x < y):
    print("x is less than y")

elif (x > y):
    print("x is greater than y")

else: # x == y
    print("x is equal to y")



# infinite loop
while True:
    print("meow")
    break



#while loop
while (x < 5):
    print(f"{x}. meow")
    x += 1



# for loop
for i in range(x):
    print(f"{i}. meow")



# include/import library
#import cs50

# import specific functions from library
#from cs50 import get_float, get_string



# define a function
def sayHi(name):
    print(f"hello {name}")



# dictionary program from wk5

words = set() # create a set which is the dictionary

def check(word):
    if word.lower() in words: # .lower() makes string lowercase
        return True
    else:
        return False

def load(dictionary):
    # open a file
    file = open(dictionary, "r") # r = read mode

    # loop through lines in file
    for line in file:
        word = line.rstrip() # removes the \n character from the string
        words.add(word) # adds word to dictionary
    
    # close a file
    file.close()
    return True

def size():
    return len(words) # return length

def unload():
    return True



# addition calculator program
a = int(input("a: ")) # int() converts input to an integer (type casting)
b = int(input("b: "))
print(a + b)


# when calling a function from a library, you need to refer to the library before the function
import math
from multiprocessing.sharedctypes import Value
print(math.sqrt(9))



# exceptions - use 'try' and 'except' to detect exceptions (e.g. if a person inputs a word instead of an int)
try:
    num = int(input("Enter an int: "))
except ValueError:
    print("That's not an int!")


# try until they get it right
while True:
    try:
        a = int(input("Enter a number: "))
        break
    except ValueError:
        print("Invalid input.")



# print number with more sig. figs.
z = 0.01
print(f"{z:.50f}")



# check if a value is in a list
if "yolo" in ["a", "b", "c", "yolo"]:
    print("Yolo is there!")



# chain dot notation :) e.g. 
a = input("Enter a string: ").lower()



# do while loop 
while True:
    a = int(input("Enter an int: "))
    if (a > 0):
        break
# or
a = int(input("Enter an int: "))
while (a > 0):
    # do stuff
    a = int(input("Enter an int: "))



# print function actually can take two parameters - the 2nd one refers to the "end" of the printed string (by default it is \n)
print("?", end="") 
print("a") # these two lines will print ?a

# multiply strings
print("#" * 3) # prints ###



# add elements to a list
scores = []
for i in range(3):
    x = int(input("Enter a score: "))
    
    scores.append(x)
    # or
    scores += [x]



# loop through characters in a string
string1 = "Hello!"
for character in string1:
    print(character)



# use command line arguments
from sys import argv
if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")



# slice a list
a = [1, 2, 3, 4, 5]
print(a[1:]) # prints 2, 3, 4, 5
print(a[:-1]) # prints 1, 2, 3, 4



#e exit from the program with an exit code
import sys
#sys.exit(1) # exit code of 1

# exit a program
#exit()



# dictionary
dict1 = {
    "Person1": "0475927583",
    "Person2": "0285648491"
}
print(dict1["Person1"]) # prints 0475927583
print(dict1["Person2"]) # prints 0285648491

# loop through a dictionary
for person in dict1: # person = key
    print(f"{person} has a phone number {dict1[person]}")







# CSV (comma separated values)

# write lines to a CSV
import csv

name = input("Name: ")
number = input("Number: ")

file = open("phonebook.csv", "a")

writer = csv.writer(file)
writer.writerow([name, number])

file.close()

# or

import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file: # alternative so that you dont need to close the file
    writer = csv.writer(file)
    writer.writerow([name, number])


# read lines from a CSV
with open("hogwarts.csv", "r") as file:
    reader = csv.reader(file) # csv library will open and read the file
    
    next(reader) # skips a line (e.g. in this case, it does not read the first line of the CSV)
    
    for row in reader: # loops through file, where row is a list of each comma separated value
        house = row[1]
        print(house)
# OR
with open("hogwarts.csv", "r") as file:
    reader = csv.DictReader(file) # csv library will open and read the file as a dictionary
    # the dictionary it returns will have keys according to the first row's values
        
    for row in reader: # loops through file, where row is a list of each comma separated value
        house = row["House"]
        print(house)







''' algorithms '''

# linear search
numbers = [3, 5, 6, 4, 8, 1, 9]

if 0 in numbers: # implements linear search automatically
    print("Found")
    sys.exit(0)

print("Not Found")
sys.exit(1)




# fun text-to-speech
'''
import pyttsx3
engine = pyttsx3.init()
engine.say("hello, world")
engine.runAndWait()
'''