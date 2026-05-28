# C01 – Pointers and Memory Model (C Language)

This document explains the core concepts of C01 with a focus on memory, pointers, and low-level program behavior.

---

# 1. MEMORY MODEL

In C, memory is a continuous sequence of bytes. Each variable is stored at a specific address.

### Example

```c
int a = 5;
```

### Internal representation

* `a` is stored in memory
* It has an address (e.g. 0x7ffee3a12c)
* The value `5` is stored at that address

### Key idea

A variable = (address + value)

---

# 2. POINTERS

A pointer is a variable that stores the memory address of another variable.

### Declaration

```c
int *p;
```

* `p` is a pointer to an integer
* It stores an address, not a value

---

### Example

```c
int a = 5;
int *p = &a;
```

### Explanation

* `&a` = address of variable `a`
* `p` stores the address of `a`

---

# 3. DEREFERENCING

Dereferencing means accessing the value stored at an address.

```c
int a = 5;
int *p = &a;

printf("%d", *p);
```

### Execution

* `p` contains address of `a`
* `*p` accesses value at that address
* Output = 5

---

# 4. POINTER OPERATIONS

### Modify value through pointer

```c
int a = 5;
int *p = &a;
*p = 10;
```

### Result

* `a` becomes 10
* Because pointer writes directly into memory location

---

# 5. MEMORY ADDRESSING

Each variable has a unique address.

```c
printf("%p", &a);
```

### Concept

* `&` operator returns memory address
* Addresses are usually displayed in hexadecimal

---

# 6. STACK BEHAVIOR

Local variables are stored in the stack.

### Example

```c
void f()
{
    int a = 10;
}
```

### Behavior

* `a` is created when function starts
* `a` is destroyed when function ends

This is called automatic memory allocation.

---

# 7. POINTER AND FUNCTIONS

Pointers allow functions to modify external variables.

### Example

```c
void update(int *p)
{
    *p = 42;
}
```

### Execution

```c
int a = 5;
update(&a);
```

Result:

* `a` becomes 42

---

# 8. PASS BY VALUE vs PASS BY REFERENCE

### Pass by value

```c
void f(int a)
```

* Copies the value
* Changes do not affect original

### Pass by reference (via pointer)

```c
void f(int *a)
```

* Works on original memory
* Changes affect original variable

---

# 9. ARRAY AND POINTER RELATION

Arrays are closely related to pointers.

```c
int arr[3] = {1,2,3};
```

### Key rule

* `arr` represents the address of first element
* `arr[0] == *arr`
* `arr[i] == *(arr + i)`

---

# 10. POINTER ARITHMETIC

Pointers can move through memory.

```c
int *p = arr;
p++;
```

### Meaning

* `p++` moves pointer to next integer in memory
* Not next byte, but next element of type `int`

---

# CORE SUMMARY (C01)

* Memory is a linear address space
* Variables are memory locations
* Pointers store addresses
* Dereferencing accesses memory content
* Stack handles function-local variables
* Arrays behave like pointers in expressions

---

# IMPORTANT CONCEPT

C does not hide memory.
It exposes direct access to addresses through pointers.

Understanding C01 means understanding how software manipulates memory at runtime.
