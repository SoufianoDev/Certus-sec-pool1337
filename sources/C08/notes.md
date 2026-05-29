````markdown id="n7u3tm"
# C08 – Headers, Macros and Program Architecture (Detailed)

## Introduction

C08 introduces modular programming in C.

Before C08:
- most programs exist in one file
- logic is compact
- declarations and implementations are mixed together

After C08:
- programs become separated into modules
- declarations are isolated in headers
- implementations are separated into source files
- code becomes reusable and scalable

This is the beginning of real software architecture in C.

---

# 1. HEADER FILES (.h)

A header file contains declarations shared between source files.

Typical content:
- function prototypes
- macros
- typedefs
- structures
- constants

Example:

```c
#ifndef FT_H
# define FT_H

int ft_strlen(char *str);

#endif
````

---

## Why headers exist

Without headers:

* files cannot know external function signatures
* compiler cannot verify correctness
* code duplication increases

Headers act as interfaces between modules.

---

# 2. SOURCE FILES (.c)

Source files contain implementations.

Example:

```c
int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
```

---

# 3. INCLUDE DIRECTIVE

```c
#include "ft.h"
```

The preprocessor literally copies the content of the header into the file before compilation.

Conceptually:

```text id="8l0o7g"
main.c + ft.h
        ↓
merged source code
```

---

# 4. PREPROCESSOR

The preprocessor runs before compilation.

Main tasks:

* expand macros
* include files
* process conditions

Pipeline:

```text id="c8lg1m"
source code
    ↓
preprocessor
    ↓
compiler
    ↓
assembler
    ↓
linker
```

---

# 5. INCLUDE GUARDS

Problem:
If a header is included multiple times:

```c
#include "ft.h"
#include "ft.h"
```

Result:

* duplicate declarations
* redefinition errors

---

## Solution

```c
#ifndef FT_H
# define FT_H

...

#endif
```

---

## Internal logic

### First inclusion

```text id="j7ydtw"
FT_H undefined
→ define FT_H
→ include content
```

### Second inclusion

```text id="p1e2i8"
FT_H already defined
→ skip content
```

---

# 6. FUNCTION PROTOTYPES

Prototype:

```c
int ft_strlen(char *str);
```

Purpose:

* informs compiler about function existence
* defines return type
* defines parameter types

---

## Why prototypes matter

Without prototype:

* compiler guesses types
* incorrect calls become dangerous
* undefined behavior possible

---

# 7. MACROS

Macros are text replacements executed by the preprocessor.

Example:

```c
#define BUFFER_SIZE 42
```

Before compilation:

```text id="q5d1zh"
BUFFER_SIZE
↓
42
```

---

# 8. MACRO FUNCTIONS

Example:

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

---

## Important behavior

Macros are NOT functions.

They:

* do not allocate stack frames
* do not enforce types
* are pure text substitution

---

## Common danger

```c
#define SQUARE(x) x * x
```

Problem:

```c
SQUARE(1 + 2)
↓
1 + 2 * 1 + 2
```

Incorrect result due to precedence.

Correct version:

```c
#define SQUARE(x) ((x) * (x))
```

---

# 9. typedef

`typedef` creates aliases for types.

Example:

```c
typedef unsigned long t_ulong;
```

---

## Purpose

* simplify complex declarations
* improve readability
* standardize naming conventions

---

# 10. STRUCTURES IN HEADERS

Structures are usually declared in headers for reuse.

Example:

```c
typedef struct s_point
{
    int x;
    int y;
} t_point;
```

---

## Why in headers

If structure is declared only in one file:

* other files cannot use it

Headers expose shared structures globally.

---

# 11. MULTI-FILE PROGRAMS

Example architecture:

```text id="fkr3lg"
project/
├── main.c
├── parsing.c
├── utils.c
├── memory.c
├── ft.h
```

---

## Purpose of modularity

Each file has one responsibility:

* parsing
* memory
* utilities
* algorithms

This reduces complexity.

---

# 12. LINKING PROCESS

Each `.c` file is compiled independently:

```text id="0qzn0q"
main.c   → main.o
utils.c  → utils.o
memory.c → memory.o
```

Then linker combines all object files:

```text id="ndq0p9"
main.o + utils.o + memory.o
            ↓
       executable
```

---

# 13. SEPARATION OF DECLARATION AND IMPLEMENTATION

## Header (.h)

Contains:

* declarations
* interfaces

## Source (.c)

Contains:

* implementation logic

This separation is fundamental in software engineering.

---

# 14. REAL PURPOSE OF C08

C08 teaches:

* modular architecture
* scalable organization
* compiler communication
* reusable interfaces
* preprocessor mechanics

This is the first step toward:

* large systems
* operating systems
* libraries
* real-world software projects

---

# CORE SUMMARY

* headers expose declarations
* source files contain implementations
* include guards prevent duplication
* macros are preprocessor substitutions
* typedef simplifies type usage
* modularity improves scalability
* linker combines compiled modules
* C08 introduces real software architecture

```
```
