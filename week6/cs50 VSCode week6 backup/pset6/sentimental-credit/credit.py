import cs50


def main():
    input1 = cs50.get_string("Number: ")

    inputLen = len(input1)

    # luhn's alg
    total = 0
    for i in range(1, inputLen+1):
        q = i * -1
        if (i % 2) == 0:
            total += digitSum(2 * int(input1[q]))
        else:
            total += int(input1[q])

    if (total % 10) != 0:
        return "INVALID"

    # check if american express
    if (inputLen == 15) and (input1[:2] in ["34", "37"]):
        return "AMEX"

    # check if mastercard
    if (inputLen == 16) and ((int(input1[:2]) >= 51) and (int(input1[:2]) <= 55)):
        return "MASTERCARD"

    # check if visa
    if ((inputLen == 16) or (inputLen == 13)) and (input1[0] == "4"):
        return "VISA"

    return "INVALID"


def digitSum(num1):
    total = 0
    for i in str(num1):
        total += int(i)

    return total


print(main())
