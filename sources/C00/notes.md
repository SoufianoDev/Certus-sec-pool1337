# C00 – Complete C Language Fundamentals Guide

This document explains the core concepts of C00 in depth, focusing on how the program behaves at runtime and how each construct maps to low-level execution.

---

# 1. VARIABLES

A variable is a named region of memory used to store a value of a specific type.

```c
int a = 5;
```

### Components

* Type: `int` (defines memory size and interpretation)
* Identifier: `a`
* Value: `5`

### Internal behavior

During compilation, the variable name is mapped to a memory address.
At runtime, the CPU accesses the value using that address.

A variable is not the value itself; it is a symbolic reference to a memory location.

### Assignment

```c
a = 10;
```

This operation overwrites the existing value in the same memory location (or rebinds it depending on optimization and scope rules).

---

# 2. CONDITIONS (if / else)

Conditional statements control execution flow based on boolean evaluation.

```c
if (a > 10)
    printf("BIG");
else
    printf("SMALL");
```

### Execution model

1. Expression evaluation: `a > 10`
2. Boolean result: true or false
3. Branch selection:

   * true → execute if-block
   * false → execute else-block

### Low-level mapping

At assembly level, conditions become jump instructions:

* conditional jump if true
* conditional jump if false

Thus, conditions are control flow redirections in the program execution path.

---

# 3. LOOPS (while / for)

Loops represent repeated execution using conditional jumps.

---

## while loop

```c
int i = 0;
while (i < 3)
{
    printf("%d", i);
    i++;
}
```

### Execution flow

1. Evaluate condition `i < 3`
2. If true → execute body
3. Update variable
4. Jump back to condition
5. Repeat until condition becomes false

### Key idea

A loop is a backward jump in control flow combined with a condition check.

---

## for loop

```c
for (int i = 0; i < 3; i++)
    printf("%d", i);
```

### Structure mapping

* Initialization: executed once
* Condition: checked before each iteration
* Update: executed after each iteration

Equivalent to:

```c
int i = 0;
while (i < 3)
{
    printf("%d", i);
    i++;
}
```

---

# 4. SYSTEM CALLS

System calls provide controlled interaction between user programs and the operating system kernel.

```c
#include <unistd.h>
write(1, "Hello", 5);
```

### Explanation

* `1` refers to standard output (stdout)
* The program does not write directly to hardware
* The kernel handles the actual output operation

### Execution model

1. User program requests service
2. CPU switches to kernel mode
3. Kernel processes request
4. Kernel interacts with hardware
5. Control returns to user program

System calls are the boundary between user space and kernel space.

---

# 5. COMPILER

A compiler transforms high-level C code into machine-executable binary through multiple stages.

### Pipeline

1. Preprocessing

   * Expands includes and macros
   * Removes comments

2. Compilation

   * Converts C into assembly code

3. Assembly

   * Converts assembly into object code (binary format)

4. Linking

   * Combines object files and libraries
   * Produces final executable

### Final output

A binary file directly executed by the operating system.

---

# 6. EXECUTION MODEL

Consider the following program:

```c
int main()
{
    int a = 3;
    if (a > 2)
        printf("OK");
}
```

### Step-by-step execution

1. Program starts at `main`
2. Variable `a` is allocated and assigned value 3
3. Condition `a > 2` is evaluated
4. Result is true
5. `printf("OK")` is executed
6. Program terminates

---

# CORE SUMMARY (C00)

* Variables: memory storage abstraction
* Conditions: control flow decision points
* Loops: repeated execution via jumps
* System calls: OS interaction layer
* Compiler: translation from source code to machine code

---

# IMPORTANT CONCEPT

C programming is not a sequence of isolated instructions.
It is a structured transformation of data and control flow executed by the CPU.

CPU execution model:

* Fetch instruction
* Decode instruction
* Execute instruction

C code is a high-level abstraction over this cycle.
