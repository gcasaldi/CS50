import sys
import cs50

def main():

    # check if arguments in command line including ./caesar is more than 2
    if len(sys.argv) != 2:
        print("Usage: python k")
        exit(1)

    # assigning of variables
    key = int(sys.argv[1])
    encrypted = []

    # ask for user input
    message = cs50.get_string("plaintext: ")

    # to iterate through the inputted message
    for index in message:

        # to ensure only alphabets are translated
        if index.isalpha():

            # append the char to 'encrypted' list
            encrypted.append(encrypt(index, key))

        else:
            encrypted.append(index)

    print("ciphertext: ", end="")

    # to iterate through the stored "encrypted" chars and print 1 x 1
    for a in range(len(encrypted)):
        print(encrypted[a], end="")

    print()

    exit(0)

# definition of the function the encrypts the char
def encrypt(char, key):

    # formula for upper case
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)

    # formula for lower case
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)

if __name__ == "__main__":
    main()