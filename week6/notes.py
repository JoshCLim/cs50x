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
    dict        objects         has keys and values
    set


python and the command line 
    python hello.py

python is "interpreted" not "compiled"

python is slower than C coz it's interpreted

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

else:
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