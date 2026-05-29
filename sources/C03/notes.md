# C03 – Structures, Memory Layout and Data Organization (C Language)

This document explains how C organizes complex data using structures and how memory layout behaves internally.

---

# 1. STRUCTURES (struct)

A structure groups multiple variables under a single custom type.

```c
struct User
{
    int age;
    char grade;
};
```

### Purpose

Structures allow related data to be stored together.

### Components

* `struct User` = custom type
* `age` and `grade` = structure members

---

# 2. STRUCTURE INSTANCE

```c
struct User u;
```

### Behavior

Memory is allocated for all members together.

Example:

```c
u.age = 19;
u.grade = 'A';
```

The structure stores both values in contiguous memory.

---

# 3. MEMORY LAYOUT

Structures occupy a continuous block of memory.

Example:

```c
struct Data
{
    int x;
    char y;
};
```

### Internal layout

* `x` stored first
* `y` stored after x

The compiler may insert padding bytes for alignment.

---

# 4. MEMORY ALIGNMENT

Processors access aligned memory more efficiently.

Example:

```c
struct Test
{
    char a;
    int b;
};
```

### Possible layout

* char = 1 byte
* padding = 3 bytes
* int = 4 bytes

Total size may become 8 bytes instead of 5.

---

# 5. ACCESSING MEMBERS

```c
u.age = 20;
```

### Operator

* `.` accesses structure members

---

# 6. POINTER TO STRUCTURE

```c
struct User *p;
```

A structure pointer stores the address of a structure.

Example:

```c
p = &u;
```

---

# 7. ARROW OPERATOR

Instead of:

```c
(*p).age = 20;
```

C provides:

```c
p->age = 20;
```

### Meaning

* `->` dereferences pointer and accesses member directly

---

# 8. STRUCTURES AND FUNCTIONS

Structures can be passed to functions.

### By value

```c
void f(struct User u)
```

Copies entire structure.

### By pointer

```c
void f(struct User *u)
```

Works directly on original memory.

---

# 9. NESTED STRUCTURES

Structures can contain other structures.

```c
struct Point
{
    int x;
    int y;
};

struct Player
{
    struct Point pos;
    int hp;
};
```

This creates hierarchical memory organization.

---

# 10. TYPEDEF

`typedef` creates aliases for types.

Example:

```c
typedef struct User
{
    int age;
} User;
```

Now:

```c
User u;
```

instead of:

```c
struct User u;
```

---

# 11. STRUCTURE COPYING

Structures can be copied directly.

```c
User a;
User b;

b = a;
```

### Behavior

All members are copied.

This is different from arrays.

---

# 12. STRUCTURE SIZE

```c
sizeof(struct User)
```

Returns total memory occupied including padding.

---

# CORE SUMMARY (C03)

* Structures organize related data
* Members are stored in contiguous memory
* Alignment affects memory size
* Structure pointers allow direct memory manipulation
* `->` combines dereference and member access
* typedef simplifies complex declarations

---

# IMPORTANT CONCEPT

Structures are memory layouts defined by the programmer.

C allows direct control over how data is organized in memory, making structures fundamental for systems programming, networking, operating systems, and low-level software design.
