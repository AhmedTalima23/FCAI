# Ahmed mohamed mahmoud 20230034
# Abdallah bassem 20231101
# Mariam Tamer 20230392
# ===============================

# ===============================

# Test code to test the binary conversions :
#  input number is 1001
#  expected output :
# From binary to decimal = 9
# From binary to binary = 1001 
# From binary to octal = 11
# From binary to hexadecimal = 9
# ===============================

# ===============================
# Test code to test the decimal conversions :
#  input number is 23
#  expected output :
# From decimal to decimal = 23
# From decimal to binary = 10111 
# From decimal to octal = 27
# From decimal to hexadecimal = 17
# ===============================

# ===============================
# Test code to test the octal conversions :
#  input number is : 1234
#  expected output :
# From octal to decimal = 668
# From octal to binary = 1010011100
# From octal to octal = 1234
# From octal to hexadecimal = 29C
# ===============================

# ===============================
# Test code to test the Hexadecimal conversions :
#  input number is : A12
#  expected output :
# From hexadecimal to decimal = 2578
# From hexadecimal to binary = 101000010010
# From hexadecimal to octal = 5022
# From hexadecimal to hexadecimal = A12
# ===============================




quit = 0

# Function to get user's choice for number base (A, B, C, D)
def Choice():
    print("A) Decimal\nB) Binary\nC) Octal\nD) Hexadecimal")
    choice = input("Enter a Choice : ")
    choice = choice.upper()
    while (choice != "A") and (choice != "B") and (choice != "C") and (choice != "D"):
        # Validate user input, ask again if it's not a valid choice
        print("Please Select a valid Choice")
        choice = input("Enter a Choice: ")
        choice = choice.upper()
    return choice

# Function to display the main menu options
def mainMenu():
    print("**Numbring System Converter**")
    print("=====================")
    print("A) Insert a New Number")
    print("B) Exit Program")

# Function for the "from" conversion
def menu1():
    print("Please select the base you want to convert from")
    choice2 = Choice()
    return choice2

# Function for the "to" conversion
def menu2():
    print("Please select the base you want to convert a number to")
    choice3 = Choice()
    return choice3

# Function to check if a number is binary
def is_binary(Num):
    for digit in Num:
        if digit not in ('0', '1'):
            return False
    return True

# Function to convert binary to decimal
def biToDec(Num):
    decimalNum = 0
    i = 0
    while Num > 0:
        rem = Num % 10
        if (rem == 0) or (rem == 1):
            decimalNum += rem * (2 ** i)
            i = i + 1
            Num = Num // 10
    print("\nEquivalent Decimal Value = ", decimalNum)

# Function to convert binary to octal
def biToOct(Num):
    Octal = {0: 0, 1: 1, 10: 2, 11: 3, 100: 4, 101: 5, 110: 6, 111: 7}
    octnum = []
    while Num != 0:
        rem = Num % 1000  # Assuming 3 digits at a time
        octnum.append(Octal[rem])
        Num = Num // 1000
    octnum.reverse()
    print("\nEquivalent Octal Value =", ''.join(map(str, octnum)))

# Function to convert binary to hexadecimal
def biToHex(Num):
    hexa = []
    hexadec = []
    decnum = 0
    i = 0
    while Num > 0:
        rem = int(Num % 10)
        decnum = decnum + (rem * (2 ** i))
        i += 1
        Num = int(Num / 10)
    i = 0
    rem = 0
    while decnum > 0:
        rem = int(decnum % 16)
        if rem < 10:
            hexa.append(chr(rem + 48))
        else:
            hexa.append(chr(rem + 55))
        decnum = int(decnum / 16)
    j = 1
    for i in hexa:
        hexadec.append(hexa[len(hexa) - j])
        j += 1
    print("\nEquivalent HexaDecimal Value = ", *hexadec, sep="")

# Function to convert decimal to binary
def DecToBi(Num):
    binaryNum = 0
    i = 0
    while Num > 0:
        binaryNum = binaryNum + (Num % 2) * (10 ** i)
        Num = (Num // 2)
        i += 1
    print("\nEquivalent Binary Number Value = ", binaryNum)
    print("\n\n")

# Function to convert decimal to octal
def DecToOc(Num):
    octNum = 0
    i = 0
    while Num > 0:
        octNum = octNum + (Num % 8) * (10 ** i)
        Num = (Num // 8)
        i += 1
    print("\nEquivalent Octal Number Value = ", octNum)
    print("\n\n")

# Function to convert decimal to hexadecimal
def DecToHex(Num):
    i = 0
    hexnum = []
    while Num != 0:
        rem = Num % 16
        if rem < 10:
            rem = rem + 48
        else:
            rem = rem + 55
        rem = chr(rem)
        hexnum.insert(i, rem)
        i = i + 1
        Num = int(Num / 16)
    print("\nEquivalent Hexadecimal Value = ", end="")
    i = i - 1
    while i >= 0:
        print(end=hexnum[i])
        i = i - 1
    print()

# Function to convert octal to decimal
def OcToDec(Num):
    decNum = 0
    i = 0
    while Num > 0:
        rem = Num % 10
        decNum += rem * (8 ** i)
        i = i + 1
        Num = (Num // 10)
    print("\nEquivalent Decimal Value = ", decNum)
    print("\n\n")

# Function to convert octal to binary
def OcToBi(Num):
    i = 0
    deciml_num = 0
    binry_num = 0
    while Num != 0:
        rem = (Num % 10)
        deciml_num = deciml_num + rem * (8 ** i)
        i += 1
        Num = Num // 10
    i = 1
    while deciml_num != 0:
        rem2 = (deciml_num % 2) * i
        binry_num = binry_num + rem2
        deciml_num = deciml_num // 2
        i = i * 10
    print("\nEquivalent binary Value = ", binry_num)
    print("\n\n")

# Function to convert octal to hexadecimal
def OcToHex(Num):
    chk = 0
    i = 0
    decnum = 0
    while Num != 0:
        rem = (Num % 10)
        if rem > 7:
            chk = 1
            break
        decnum = decnum + (rem * (8 ** i))
        i = i + 1
        Num = int(Num // 10)

    if chk == 0:
        hexnum = ""
        while decnum != 0:
            rem = decnum % 16
            if rem < 10:
                rem = rem + 48
            else:
                rem = rem + 55
            rem = chr(rem)
            hexnum = hexnum + rem
            decnum = int(decnum // 16)
        hexnum = hexnum[::-1]
        print("\nEquivalent Hexadecimal Value =", hexnum)
        print("\n\n")
    else:
        print("\nInvalid Input!")

# Function to convert hexadecimal to decimal
def HexToDec(Num):
    hex_to_dec_dict = {
        '0': 0, '1': 1, '2': 2, '3': 3,
        '4': 4, '5': 5, '6': 6, '7': 7,
        '8': 8, '9': 9, 'A': 10, 'B': 11,
        'C': 12, 'D': 13, 'E': 14, 'F': 15
    }
    Num = Num.upper()
    decNum = 0
    i = 0

    while Num:
        digit = Num[-1]
        decNum += hex_to_dec_dict[digit] * (16 ** i)
        i += 1
        Num = Num[:-1]

    print("\nEquivalent Decimal Value = ", decNum)
    print("\n\n")

# Function to convert hexadecimal to binary
def HexToBi(Num):
    hex_to_bin_dict = {
        '0': '0000', '1': '0001', '2': '0010', '3': '0011',
        '4': '0100', '5': '0101', '6': '0110', '7': '0111',
        '8': '1000', '9': '1001', 'A': '1010', 'B': '1011',
        'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111'
    }

    binary_num = ''
    Num = Num.upper()

    for digit in Num:
        binary_num += hex_to_bin_dict[digit]

    print("\nEquivalent Binary Value = ", binary_num)

# Function to convert hexadecimal to octal
def HexToOc(Num):
    hex_to_bin_dict = {
        '0': '0000', '1': '0001', '2': '0010', '3': '0011',
        '4': '0100', '5': '0101', '6': '0110', '7': '0111',
        '8': '1000', '9': '1001', 'A': '1010', 'B': '1011',
        'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111'
    }

    bin_to_oct_dict = {
        '000': '0', '001': '1', '010': '2', '011': '3',
        '100': '4', '101': '5', '110': '6', '111': '7'
    }

    Num = Num.upper()
    binary_num = ''
    octal_num = ''

    # Convert hexadecimal to binary
    for digit in Num:
        binary_num += hex_to_bin_dict[digit]

    # Pad with leading zeros if necessary
    while len(binary_num) % 3 != 0:
        binary_num = '0' + binary_num

    # Convert binary to octal
    i = 0
    while i < len(binary_num):
        chunk = binary_num[i:i + 3]
        octal_num += bin_to_oct_dict[chunk]
        i += 3

    print("\nEquivalent Octal Value = ", octal_num)
    print("\n\n")

# Main loop to repeatedly present the menu and handle user choices
while quit == 0:
    mainMenu()  # Display the main menu
    choice1 = str(input("Enter a Choice : "))  # User input for the main menu choice (A/B)
    choice1 = choice1.upper()

    while (choice1 != "A") and (choice1 != "B"):
        # Validate user input, ask again if it's not a valid choice
        print("Please Select a valid Choice")
        choice1 = str(input("Enter a Choice : "))
        choice1 = choice1.upper()

    if choice1 == "A":  # If the user chooses to insert a new number
        Num = input("Please Insert a Number: ")  # Get user input for the number

    elif choice1 == "B":  # If the user chooses to exit the program
        quit = -1
        print("BYE \U0001F604")
        exit(0)

    print("--------------------")
    choice2 = menu1()  # Get user choice for the "from" conversion

    while (choice2 == 'B') and (is_binary(Num) is False):
        # If user chose binary as the "from" conversion, ensure the input is binary
        print("=====================")
        print("Your inserted number", Num, "is not from base 2")
        print("=====================")
        choice2 = menu1()

    print("--------------------")
    choice3 = menu2()  # Get user choice for the "to" conversion

    # Handle different conversion cases based on user choices
    if (choice2 == "A") and (choice3 == "A"):  # Decimal to Decimal
        print("\nEquivalent Decimal Value = ", Num)

    elif (choice2 == "A") and (choice3 == "B"):  # Decimal to Binary
        DecToBi(int(Num))

    elif (choice2 == "A") and (choice3 == "C"):  # Decimal to Octal
        DecToOc(int(Num))

    elif (choice2 == "A") and (choice3 == "D"):  # Decimal to Hexadecimal
        DecToHex(int(Num))

    elif (choice2 == "B") and (choice3 == "A"):  # Binary to Decimal
        biToDec(int(Num))

    elif (choice2 == "B") and (choice3 == "B"):  # Binary to Binary
        print("\nEquivalent binary Value = ", Num)

    elif (choice2 == "B") and (choice3 == "C"):  # Binary to Octal
        biToOct(int(Num))

    elif (choice2 == "B") and (choice3 == "D"):  # Binary to Hexadecimal
        biToHex(int(Num))

    elif (choice2 == "C") and (choice3 == "A"):  # Octal to Decimal
        OcToDec(int(Num))

    elif (choice2 == "C") and (choice3 == "B"):  # Octal to Binary
        OcToBi(int(Num))

    elif (choice2 == "C") and (choice3 == "C"):  # Octal to Octal
        print("\nEquivalent Octal Value = ", Num)

    elif (choice2 == "C") and (choice3 == "D"):  # Octal to Hexadecimal
        OcToHex(int(Num))

    elif (choice2 == "D") and (choice3 == "A"):  # Hexadecimal to Decimal
        HexToDec(Num)

    elif (choice2 == "D") and (choice3 == "B"):  # Hexadecimal to Binary
        HexToBi(Num)

    elif (choice2 == "D") and (choice3 == "C"):  # Hexadecimal to Octal
        HexToOc(Num)

    elif (choice2 == "D") and (choice3 == "D"):  # Hexadecimal to Hexadecimal
        print("\nEquivalent HexaDecimal Value = ", Num)
