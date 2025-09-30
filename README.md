# 🔢 Numbering System Converter

## 📌 Overview
This project is a **Numbering System Converter** implemented in Python.  
It allows users to convert numbers between the following bases:

- **Decimal (Base 10)**
- **Binary (Base 2)**
- **Octal (Base 8)**
- **Hexadecimal (Base 16)**

The program provides a simple **menu-driven interface** where the user selects the input base ("from") and the desired output base ("to").  

---

## 👨‍💻 Features
- Interactive **menu system** with input validation.  
- Supports conversions between **Decimal, Binary, Octal, and Hexadecimal**.  
- Detects invalid inputs (e.g., non-binary digits when binary is selected).  
- Uses custom conversion functions for each case (not Python’s built-in functions).  
- Provides **clear outputs** for every conversion.  

---

## ⚡ Menu Options

### Main Menu
Numbering System Converter

A) Insert a New Number
B) Exit Program


### Base Selection Menu

A) Decimal
B) Binary
C) Octal
D) Hexadecimal


---

## 🛠️ Implementation (Functions)

### 📂 Menu & Input Handling
- `mainMenu()` → Displays the main menu.  
- `Choice()` → Gets and validates user’s base selection (A/B/C/D).  
- `menu1()` → Base selection for **"from" conversion**.  
- `menu2()` → Base selection for **"to" conversion**.  

### 📂 Validation
- `is_binary(Num)` → Checks if the given number is a valid binary string (only `0` and `1`).  

---

### 📂 Conversion Functions

#### Binary Conversions
- `biToDec(Num)` → Binary → Decimal  
- `biToOct(Num)` → Binary → Octal  
- `biToHex(Num)` → Binary → Hexadecimal  

#### Decimal Conversions
- `DecToBi(Num)` → Decimal → Binary  
- `DecToOc(Num)` → Decimal → Octal  
- `DecToHex(Num)` → Decimal → Hexadecimal  

#### Octal Conversions
- `OcToDec(Num)` → Octal → Decimal  
- `OcToBi(Num)` → Octal → Binary  
- `OcToHex(Num)` → Octal → Hexadecimal  

#### Hexadecimal Conversions
- `HexToDec(Num)` → Hexadecimal → Decimal  
- `HexToBi(Num)` → Hexadecimal → Binary  
- `HexToOc(Num)` → Hexadecimal → Octal  

---
