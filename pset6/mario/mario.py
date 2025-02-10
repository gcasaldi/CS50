import cs50

# establish user input rules: not less than 0 and not more than 23
while True:
    height = cs50.get_int("Height: ")
    if height > -1 and height < 24:
        break

# line control formula
for line in range(height):

    # define values of space and hash
    space = height - line - 1
    hashes = line + 2

    # define formula of printing space
    for x in range(space):
        print(" ", end="")

    # define formula of printing hashtag
    for y in range(hashes):
        print("#", end="")

    print()