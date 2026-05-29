# C04 – Strings, Arrays and Low-Level Text Handling (C Language)

C04 covers how C handles arrays and strings at memory level. There is no built-in string type; everything is based on raw memory and pointer arithmetic.

---

# 1. ARRAYS

An array is a contiguous block of memory storing elements of the same type.

```c
int arr[3] = {1, 2, 3};
```

### Memory behavior

* Elements are stored sequentially
* Each element has a fixed size depending on its type
* Access is done via index or pointer arithmetic

---

# 2. ARRAYS AND POINTER RELATION

In C, the array name represents the address of its first element in most expressions.

```c
int *p = arr;
```

Equivalent expressions:

```c
arr == &arr[0]
arr[i] == *(arr + i)
```

### Key idea

Array indexing is syntactic sugar over pointer arithmetic.

---

# 3. STRINGS IN C

A string in C is an array of characters terminated by a null byte \0.

```c
char str[] = "abc";
```

### Memory representation

```
'a' 'b' 'c' '\0'
```

### Key property

* The \0 marks the end of the string
* Without it, behavior is undefined

---

# 4. STRING TRAVERSAL

Since there is no stored length, strings are processed by scanning memory.

```c
int i = 0;
while (str[i] != '\0')
{
    i++;
}
```

### Concept

Traversal stops only when the null terminator is found.

---

# 5. POINTERS AND STRINGS

```c
char *p = "abc";
```

### Important distinction

* Array string: modifiable memory
* String literal: usually read-only memory

Example of undefined behavior:

```c
p[0] = 'A';
```

---

# 6. STRING OPERATIONS CONCEPT

Standard string functions are implemented using loops:

* strlen → counts characters until \0
* strcpy → copies byte by byte
* strcmp → compares character by character

All operations are memory scans.

---

# 7. MEMORY LAYOUT OF STRINGS

Example:

```c
"hi"
```

Memory:

```
'h' -> 'i' -> '\0'
```

A pointer to a string points only to the first character.

---

# 8. MULTIDIMENSIONAL ARRAYS

```c
int matrix[2][3];
```

### Memory layout

Stored in row-major order:

```
[m00][m01][m02][m10][m11][m12]
```

All elements are contiguous in memory.

---

# 9. COMMON ERRORS

### Out of bounds access

```c
arr[10];
```

Accessing memory outside allocated range leads to undefined behavior.

### Missing null terminator

Strings without \0 cause over-read into unrelated memory.

---

# 10. ARRAYS VS POINTERS

```c
char s1[] = "hello";
char *s2 = "hello";
```

| Type    | Behavior                 |
| ------- | ------------------------ |
| Array   | Local modifiable buffer  |
| Pointer | Points to literal memory |

---

# CORE SUMMARY (C04)

* Arrays are contiguous memory blocks
* Strings are null-terminated character arrays
* No native string type exists in C
* Pointer arithmetic is fundamental
* String operations are memory traversal loops

---

# IMPORTANT CONCEPT

C treats strings as raw memory sequences.
Understanding C04 means understanding how text is physically stored and traversed in memory.
