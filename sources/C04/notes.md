# C04 – Arrays, Strings, and Number Base Conversion Concepts

## 1. Arrays

### Memory Representation

An array is a **contiguous block of memory** storing elements of the same type:

```
int arr[3] = {10, 20, 30};

Memory:
┌────────┬────────┬────────┐
│   10   │   20   │   30   │
└────────┴────────┴────────┘
  4 bytes  4 bytes  4 bytes
   (int)    (int)    (int)
```

### Array-Pointer Relationship

```
arr[i]  ==  *(arr + i)
  ↑           ↑
Index      Address calculation
```

- `arr` is the address of the first element
- `arr + i` calculates the address of element i (considering type size)
- `*(arr + i)` accesses the value at that address

---

## 2. Strings in C

### Array vs Pointer

```c
char s1[] = "hello";    // Array: modifiable
char *s2 = "hello";     // Pointer: points to read-only literal
```

```
s1:  ┌─────┬─────┬─────┬─────┬─────┬─────┐
     │ 'h' │ 'e' │ 'l' │ 'l' │ 'o' │ '\0' │  ←── Stack, modifiable
     └─────┴─────┴─────┴─────┴─────┴─────┘

s2:  ┌──────────┐
     │ 0x6000   │  ←── Stack (pointer)
     └────┬─────┘
          ↓
        ┌─────┬─────┬─────┬─────┬─────┬─────┐
        │ 'h' │ 'e' │ 'l' │ 'l' │ 'o' │ '\0' │  ←── Text segment, read-only
        └─────┴─────┴─────┴─────┴─────┴─────┘
```

### Common Errors

- **Out of bounds**: `arr[10]` when size is 3 → undefined behavior
- **Missing `\0`**: string without terminator → reads random memory

---

## 3. String to Integer Conversion

### The Idea

```
Text: "1234"
       ↓
Start from left:
Digit 1: Result = 0 × 10 + 1 = 1
Digit 2: Result = 1 × 10 + 2 = 12
Digit 3: Result = 12 × 10 + 3 = 123
Digit 4: Result = 123 × 10 + 4 = 1234
```

### Building Algorithm

```
Result = 0
For each character in text:
    If character is a digit:
        Digit = ASCII value - ASCII value of '0'
        Result = Result × 10 + Digit
    Else:
        Stop
```

### Handling Signs

```
"-42" → Recognize '-' first → set negative flag
"+42" → Recognize '+' first → set positive flag
"  42" → Skip leading spaces
```

---

## 4. Integer to String Conversion

### The Idea

```
Number: 1234
       ↓
Use repeated division:
1234 / 10 = 123 remainder 4
 123 / 10 = 12  remainder 3
  12 / 10 = 1   remainder 2
   1 / 10 = 0   remainder 1

Remainders (in reverse): 1, 2, 3, 4 → "1234"
```

### Algorithm

```
If number is negative:
    Add '-' to result
    Make number positive

While number > 0:
    Remainder = number % 10
    Convert remainder to character (remainder + '0')
    Add character to result
    Number = number / 10

Reverse the result (since we collected it backwards)
```

---

## 5. Number Bases

### The Idea

The same number can be represented in different bases:

```
Number 42:
In decimal (base 10):  42
In binary (base 2):    101010
In hexadecimal (base 16): 2a
In octal (base 8):     52
```

### Converting from Decimal to Any Base

```
Number: 42
Base: 16 (hexadecimal)

42 / 16 = 2 remainder 10 → 'a'
 2 / 16 = 0 remainder 2  → '2'

Result (in reverse): "2a"
```

### Character Table for Bases

```
Values 0-9:   ←──→  '0'-'9'
Values 10-15: ←──→  'a'-'f'
Values 16-35: ←──→  'a'-'z' (for larger bases)
```

### Validating a Base

Rules for a valid base string:
- Must contain at least 2 characters
- No duplicate characters
- No '+' or '-'
- No whitespace

---

## 6. Converting from Any Base to Decimal

### The Idea

```
Text: "2a" in hexadecimal base
       ↓
Start from left:
Character '2': value is 2
Result = 0 × 16 + 2 = 2

Character 'a': value is 10
Result = 2 × 16 + 10 = 42
```

### Algorithm

```
Result = 0
For each character in text:
    Find character's value in base (index in base string)
    Result = Result × base_length + character_value
```

---

## 7. Multidimensional Arrays

### Memory Layout

```c
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

```
In memory (Row Major order):
┌─────┬─────┬─────┬─────┬─────┬─────┐
│  1  │  2  │  3  │  4  │  5  │  6  │
└─────┴─────┴─────┴─────┴─────┴─────┘
 [0,0] [0,1] [0,2] [1,0] [1,1] [1,2]
```

### Access

```
matrix[i][j] = *(matrix + i × 3 + j)
```

---

## Summary

| Concept | Core Idea |
|---------|-----------|
| **Array** | Contiguous memory block |
| **Index** | `arr[i] == *(arr + i)` |
| **String** | Character array + `\0` |
| **Text→Number** | `× 10 + digit` from left |
| **Number→Text** | `/ 10` and collect remainders |
| **Base** | The radix determines symbol count |
| **Conversion** | Division/remainder for down, `× base + digit` for up |
| **Multidimensional** | Row-major order in memory |
