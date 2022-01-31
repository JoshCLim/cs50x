from cs50 import get_int
num = int(get_int(("Height: ")))

while (num > 8) or (num < 1):
    num = int(get_int(("Height: ")))

for i in range(1, num+1):
    print(' '*(num - i) + "#" * i + '  ' + ("#" * i))