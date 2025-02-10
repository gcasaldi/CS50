import cs50

# user input specifications: input should not be < 0
while True:
    dollars = cs50.get_float("Changed owed: ")
    if dollars > 0:
        break

# convert input (dollars) to integer (cents)
# int() is placed to convert the dollar which is in type float to type int
cents = int(dollars * 100)

# check if quotient of cents divided by the coin change (25) used is more than 1
# if more than 1, it means the coin change can be used since the cent is higher than the coin change
quotient_25 = int(cents / 25)

# declare the initial amount of the coin counter
coins = 0

if quotient_25 >= 1:
    cents = cents - (25 * quotient_25)
    coins = coins + (1.0 * quotient_25)

# the rest are patterned with the 25 change
quotient_10 = int(cents / 10)

if quotient_10 >= 1:
    cents = cents - (10 * quotient_10)
    coins = coins + (1 * quotient_10)

quotient_5 = int(cents / 5)

if quotient_5 >= 1:
    cents = cents - (5 * quotient_5)
    coins = coins + (1 * quotient_5)

quotient_1 = int(cents / 1)

if quotient_1 >= 1:
    cents = cents - (1 * quotient_1)
    coins = coins + (1 * quotient_1)

# print overall count from coin counter
print(int(coins))