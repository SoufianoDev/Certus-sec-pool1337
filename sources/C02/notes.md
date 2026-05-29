# C02 – String Concepts in C

## 1. What is a String in C?

C has **no built-in string type**. A string is just an **array of characters** ending with a special character called the **null terminator** (`\0`).

### Memory Representation

```
The string "abc" is stored as:
┌─────┬─────┬─────┬─────┐
│ 'a' │ 'b' │ 'c' │ '\0' │
└─────┴─────┴─────┴─────┘
  ↓     ↓     ↓     ↓
First  Second Third  End
char   char   char   marker
```

### Why `\0` is Essential

- There is **no length counter** embedded in the string
- Functions that process strings rely on `\0` to know where to stop
- Without `\0`, a function will read random memory (undefined behavior)

---

## 2. String Copying

### The Fundamental Problem

In C, **you cannot copy a string using `=`**:

```c
char s1[] = "hello";
char s2[10];
s2 = s1;  // ❌ ERROR! This copies the address, not the content
```

`=` copies the **pointer** (the memory address), not the **content**.

### The Solution: Byte-by-Byte Copy

You must copy each character individually until `\0`:

```
Source:  'H' 'e' 'l' 'l' 'o' '\0'
          ↓   ↓   ↓   ↓   ↓   ↓
Dest:    'H' 'e' 'l' 'l' 'o' '\0'
```

### The Concept of "Bounded Copy"

When copying with a maximum limit `n`:
- If source is shorter than `n` → pad with `\0`
- If source is longer than `n` → may not add `\0` → **danger!**

---

## 3. String Length

### The Concept

To find the length, traverse until `\0`:

```
"Hello"
  ↓
H → e → l → l → o → \0
  ↓
Count: 5 characters (not including \0)
```

### Time Complexity

- **O(n)** where n is the string length
- You must visit every character

---

## 4. String Comparison

### Why `==` Does Not Work

```
String 1:  "abc" ←── address 0x1000
String 2:  "abc" ←── address 0x2000

s1 == s2  ←── compares 0x1000 with 0x2000 → false!
```

Even if the content is identical, strings may be at **different memory locations**.

### The Principle: Character-by-Character Comparison

Compare character by character until you find a difference:

```
"abc" vs "abd"
  ↓
  a == a → continue
  ↓
  b == b → continue
  ↓
  c ≠ d → result: c - d = negative
```

### Lexicographical Order

Comparison depends on **ASCII values** of characters:

```
'0'(48) < '9'(57) < 'A'(65) < 'Z'(90) < 'a'(97) < 'z'(122)
```

- Numbers come before letters
- Uppercase comes before lowercase

---

## 5. String Concatenation

### The Principle

Append one string to the **end** of another:

```
Before:  "Hello\0"        " World\0"
            ↓
         Find \0 here
            ↓
         Start copying from here
            ↓
After:   "Hello World\0"
```

### Steps:
1. Find the end of the first string (locate `\0`)
2. Start copying from that position
3. Copy the second string until `\0`
4. Add `\0` at the end

### Buffer Overflow Risk

```
Buffer: only 6 bytes
"Hi" + " World" = "Hi World" (8 bytes + 1)
                    ↑
            Buffer overflow! Writing to unallocated memory
```

---

## 6. Character Classification

### The Idea

Every character in C is actually an **ASCII number** (0-127). You can check its type by comparing its value:

```
Is the character alphabetic?
  ↓
Is its value between 'a'(97) and 'z'(122)?
OR
Is its value between 'A'(65) and 'Z'(90)?
```

### Uses
- Input validation
- Text filtering
- Password strength checking

---

## 7. Case Conversion

### The Mathematical Idea

In ASCII, the difference between uppercase and lowercase is constant:

```
'a'(97) - 'A'(65) = 32
```

```
To uppercase:  'a' → 'A'  (97 - 32 = 65)
To lowercase:  'A' → 'a'  (65 + 32 = 97)
```

### Word Capitalization

The idea: track the beginning of a word:
- If previous character is **not** alphabetic → this is a new word → uppercase the letter
- If previous character is alphabetic → lowercase the letter

---

## 8. Non-Printable Characters

### The Problem

Some characters cannot be displayed (like null, bell, delete):

```
Value 0:   NUL (null)
Value 7:   BEL (bell)
Value 127: DEL (delete)
```

### The Solution: Hexadecimal Encoding

```
Non-printable character (value 10):
  ↓
10 / 16 = 0 remainder 10 → 'a'
  ↓
Representation: "\0a"
```

Use a conversion table: `0→'0'`, `10→'a'`, `15→'f'`

---

## 9. Memory Dump

### The Idea

Display raw memory content in a readable format:

```
Address: 0x7ffee3a12c
Hex:     48 65 6c 6c 6f 00
Text:     H  e  l  l  o  .
```

- **Address**: starting location in memory
- **Hex**: each byte in hexadecimal value
- **Text**: printable character, or `.` for non-printable

---

## 10. Safe Copy (strlcpy Concept)

### The Problem

`strcpy` and `strncpy` may cause issues:
- `strcpy`: no size check → buffer overflow
- `strncpy`: may not add `\0` if `n` is too small

### The Solution: strlcpy

```
Idea: copy at most (n-1) characters, guarantee \0 at position n

Buffer: 5 bytes
"Hello World" → copy 4 chars + \0
Result: "Hell\0"
```

### What does it return?

Returns the **length of the source string** (not the copied part). This allows the user to know if the text was truncated.

---

## Summary

| Concept | Core Idea |
|---------|-----------|
| **String** | Character array + `\0` |
| **Length** | Count characters until `\0` |
| **Copy** | Byte by byte, `=` does not work |
| **Compare** | Character by character, `==` compares addresses |
| **Concatenate** | Start from end of first string |
| **Search** | Nested loops |
| **Validate** | Compare ASCII values |
| **Case** | Add/subtract 32 |
| **Hex** | Divide by 16, use remainder |
| **Safe** | `n-1` for copy + `\0` at n |
