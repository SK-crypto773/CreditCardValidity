# Program that checks for valid VISA, American Express, and Mastercard card numbers using Luhn’s Algorithm
import cs50


def main():
    while True:
        credit_card = cs50.get_int("Number: ")
        if (credit_card >= 0):
            break
    # Check if credit card is valid
    check_validity(credit_card)


# Evaluating the credit card number
def check_validity(ccn):
    length = get_length(ccn)
    # Check the length
    # Check_sum
    if (checklength(length) == True and checksum(ccn, length) == True) == False:
        print("INVALID")
        return
    # Check/Print the brand
    print_credit_card_brand(ccn)


# Finding the length
def get_length(n):
    length = 0
    while n > 0:
        length = length + 1
        n = n // 10
    return length


# Checking the length
def checklength(length):
    if (length == 13 or length == 15 or length == 16):
        return True
    return False


# Checksum using Luhn's Algorithm
def checksum(ccn, length):
    summation = 0
    for i in range(length):
        if (i % 2 == 0):
            summation = summation + (ccn % 10)
        else:
            digit = 2 * (ccn % 10)
            summation = summation + (digit // 10 + digit % 10)
        ccn = ccn // 10
    if (summation % 10 == 0):
        return True
    return False


# Printing the credit card brands
def print_credit_card_brand(ccn):

    # AMEX
    if ((ccn >= 34e13 and ccn < 35e13) or (ccn >= 37e13 and ccn < 38e13)):

        print("AMEX")

    # MASTERCARD
    elif (ccn >= 51e14 and ccn < 56e14):

        print("MASTERCARD")

    # VISA
    elif ((ccn >= 4e12 and ccn < 5e12) or (ccn >= 4e15 and ccn < 5e15)):

        print("VISA")

    # IF NONE OF THOSE
    else:

        print("INVALID")


main()