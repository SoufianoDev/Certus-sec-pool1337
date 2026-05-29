# C03 – String Comparison and Concatenation Concepts

## 1. String Comparison

### Why `==` Cannot Be Used

In C, a pointer holds a **memory address**, not **content**:

```
First string:   "abc" ←── address 0x1000
Second string:  "abc" ←── address 0x2000

s1 == s2  ←── compares 0x1000 with 0x2000 → false!
```

Even if the text is identical, strings may be at **different locations** in memory.

### The Principle: Character-by-Character

Compare character by character until a difference is found:

```
String 1:  a  b  c  \0
             ↓  ↓  ↓  ↓
String 2:  a  b  d  \0
             ↓  ↓  ↓
          match match different!
```

### Comparison Result

- **Zero**: strings are completely identical
- **Positive**: first string is "greater" (its different character has higher ASCII value)
- **Negative**: first string is "smaller" (its different character has lower ASCII value)

### Lexicographical Order

```
ASCII ordering:
'0'(48) < '1'(49) < ... < '9'(57) < 'A'(65) < ... < 'Z'(90) < 'a'(97) < ... < 'z'(122)

Examples:
"Apple" < "apple"    (A=65 < a=97)
"10" < "2"           ('1'=49 < '2'=50)
"abc" < "abcd"       (first one ends first)
```

---

## 2. Bounded Comparison

### The Idea

Compare **only the first n characters**, regardless of the rest:

```
"HelloWorld" vs "HelloThere"  (n=5)
     ↓
"Hello" == "Hello" → match!
```

### Uses
- Checking prefix (beginning of string)
- Comparing filenames (without extension)
- Keyword searching

---

## 3. String Concatenation

### The Principle

Add a string to the **end** of another string:

```
First string:    "Hello\0"
                     ↓
                  Find \0 here
                     ↓
Second string:   " World\0"
                     ↓
                  Start copying from here
                     ↓
Result:          "Hello World\0"
```

### Steps:
1. Move through the first string until you find `\0`
2. Start copying from that position
3. Copy the second string until `\0`
4. Add `\0` at the end

### Buffer Overflow Danger

```
Allocated buffer: only 6 bytes
"Hello" (5 bytes + 1 for \0)

Want to add: " World" (6 bytes)
              ↓
Result: 11 bytes > 6 bytes → overflow!
              ↓
Writing to unallocated memory → undefined behavior
```

### The Solution: Bounded Concatenation

Add **at most n characters** from the second string:

```
Buffer: 10 bytes
"Hello" + " World" (n=3)
    ↓
"Hello Wor" (9 bytes + \0)
```

---

## 4. Substring Search

### The Problem

We want to know: is "World" inside "Hello World"?

### Naive Algorithm

```
Text:    "Hello World"
Search:  "World"

Check every position:
Position 0: "Hello..." ≠ "World" ❌
Position 1: "ello..."  ≠ "World" ❌
Position 2: "llo..."   ≠ "World" ❌
...
Position 6: "World"    == "World" ✅
```

### Implementation: Nested Loops

- **Outer loop**: move through the main text (position by position)
- **Inner loop**: compare the substring from each position
- If all characters match → found it!
- If text ends without finding → not present

---

## 5. Safe Concatenation (strlcat Concept)

### The Problem with strcat and strncat

- `strcat`: no size check → buffer overflow
- `strncat`: adds n chars + `\0`, but doesn't check if buffer is big enough

### The Solution: strlcat

```
Idea: know the total buffer size, guarantee no overflow

Buffer: 10 bytes
"Hello" already there (5 bytes + 1)
Remaining: 4 bytes (10 - 5 - 1 for \0)

Add: " World" (6 bytes)
      ↓
Add only 3 characters (4 - 1 for \0)
Result: "Hello Wor\0"
```

### What does it return?

Returns the **total length the concatenated string would have been** if the buffer was large enough. This allows the user to know if the text was truncated.

---

## Summary

| Concept | Core Idea |
|---------|-----------|
| **Comparison** | Character by character, `==` does not work |
| **Ordering** | Depends on ASCII values |
| **Bounded** | Compare only first n characters |
| **Concatenate** | Start from end of first string |
| **Search** | Nested loops |
| **Safe** | Check buffer size |
| **Application** | Sorting, searching, filtering |
