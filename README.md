# 🧮 Low-Level Programming in C

This repository contains small C programs focusing on **bitwise operations**, **array manipulation**, and **big integer arithmetic** — all written from scratch to understand low-level data handling and computation.

---

## 🎯 Overview

These programs explore how data is represented and processed at the bit level.  
They include implementations for handling 18-bit numbers, performing large integer arithmetic, and using arrays efficiently.

---

## 🧠 Key Programs

### 🧩 1. 18-bit Number Analyzer
- Finds the **minimum** and **maximum** from an array of 18-bit unsigned numbers.
- Two approaches implemented:
  - Accessing bits **individually**.
  - Reading the **entire 18-bit number** as a unit.
- Demonstrates understanding of bit manipulation, shifting, and masking.

### ➕ 2. Big Integer Addition
- Adds large integers that exceed built-in data type limits.
- Operates by processing digits as **strings** and simulating manual addition.
- Useful for understanding memory and arithmetic logic handling beyond native limits.

### ⚙️ 3. Array and Data Manipulation Utilities
- Performs arithmetic and logical operations on arrays using bitwise logic.
- Focus on control structures, efficient looping, and data representation in memory.

---

## 🧩 How to Compile and Run

Each program can be compiled and executed using GCC.

```bash
# Compile
gcc 18_bit_1.c -o 18_bit_1
gcc 18_bit_2.c -o 18_bit_2
gcc bigadd.c -o bigadd

# Run
./18_bit_1
./18_bit_2
./bigadd
```

---

## 🗂️ Files

```
18_bit_1.c       # Accesses 18-bit numbers bit by bit
18_bit_2.c       # Reads 18-bit numbers as a whole
bigadd.c         # Adds large integers
7.c, 11.c        # Additional small array/bitwise utilities
README.md        # Project summary and compilation steps
```

---

## 💡 Concepts Practiced

- Bit manipulation (AND, OR, XOR, shifting, masking)
- Memory efficiency and representation
- Loops and control structures in C
- Handling integers beyond built-in data types

---
