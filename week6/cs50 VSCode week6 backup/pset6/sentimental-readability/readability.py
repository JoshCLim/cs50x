import cs50


def countLetters(text):
    count = 0
    for letter in text:
        if (ord(letter) >= 65 and ord(letter) <= 90) or (ord(letter) >= 97 and ord(letter) <= 122):
            count += 1

    return count


def countWords(text):
    words = text.split(' ')
    return len(words)


def countSentences(text):
    sentences = text.replace('?', '.').replace('!', '.').split('.')
    return len(sentences) - 1


def main():
    input1 = cs50.get_string("Text: ")

    l = countLetters(input1)
    w = countWords(input1)
    s = countSentences(input1)

    print(f"Letters: {l}, Words: {w}, Sentences: {s}")

    multiplier = 100 / w

    ans = 0.0588 * (l * multiplier) - 0.296 * (s * multiplier) - 15.8

    rounded = round(ans)

    if rounded < 1:
        print("Before Grade 1")
    elif rounded > 16:
        print("Grade 16+")
    else:
        print(f"Grade {rounded}")


main()