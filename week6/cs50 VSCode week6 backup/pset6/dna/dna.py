import csv
import sys


def main():

    # TODO: Check for command-line usage
    if not(len(sys.argv) == 3):
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database1 = []

    file1 = open(sys.argv[1], "r")
    reader1 = csv.DictReader(file1)

    for row in reader1:
        entry = {}

        for key in row:
            entry[key] = row[key]

        database1.append(entry)

    file1.close()

    # TODO: Read DNA sequence file into a variable
    file2 = open(sys.argv[2], "r")

    sequence = file2.read()

    file2.close()

    # TODO: Find longest match of each STR in DNA sequence
    longest = {}

    for key in database1[0]:
        if not(key == "name"):
            longest[key] = longest_match(sequence, key)

    # TODO: Check database for matching profiles
    for item in database1:
        match = True

        for key in longest:
            if not(str(longest[key]) == item[key]):
                match = False

        if match == True:
            print(item['name'])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
