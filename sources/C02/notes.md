# C02 – Functions, Recursion and Stack Behavior (C Language)

This document covers C02 fundamentals with focus on function calls, execution stack, parameter passing, and recursion mechanics at runtime.

---

# 1. FUNCTIONS (Concept)

A function is a reusable block of code executed when called.

```c
int add(int a, int b)
{
    return a + b;
}
```

### Components

* Return type: `int`
* Function name: `add`
* Parameters: `a`, `b`
* Return value: `a + b`

### Execution idea

A function is not executed until it is called.

---

# 2. FUNCTION CALL MECHANISM

When a function is called, the program:

1. Pushes arguments into memory (stack)
2. Jumps to function code
3. Executes instructions
4. Returns result
5. Restores previous execution state

---

# 3. STACK FRAME

Each function call creates a stack frame.

Example:

```c
int main()
{
    int x = add(2, 3);
}
```

### Stack behavior

* main() frame is created
* add() frame is pushed on top
* add() executes
* add() frame is removed
* control returns to main()

---

# 4. PARAMETER PASSING

C uses pass-by-value.

```c
void f(int a)
{
    a = 10;
}
```

### Behavior

* A copy of the variable is created
* Original variable is NOT modified

---

# 5. PASS BY VALUE VS EFFECT

### Example

```c
void update(int a)
{
    a = 99;
}

int main()
{
    int x = 5;
    update(x);
}
```

### Result

* x remains 5
* because only a copy was modified

---

# 6. RECURSION

Recursion is a function that calls itself.

```c
int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}
```

---

# 7. RECURSION EXECUTION MODEL

Example: fact(3)

### Call stack growth

fact(3)
→ fact(2)
→ fact(1)
→ stop condition

### Unwinding phase

fact(1) = 1
fact(2) = 2 * 1 = 2
fact(3) = 3 * 2 = 6

---

# 8. STACK OVERFLOW

If recursion has no stopping condition:

```c
void f()
{
    f();
}
```

### Result

* infinite function calls
* stack memory fills up
* program crashes (stack overflow)

---

# 9. RETURN MECHANISM

When a function finishes:

* return value is stored
* stack frame is removed
* execution continues in caller

---

# 10. FUNCTION PROTOTYPE

Declaration before definition:

```c
int add(int, int);
```

Used by compiler for type checking before full definition.

---

# CORE SUMMARY (C02)

* Functions are execution units
* Each call creates a stack frame
* C uses pass-by-value
* Recursion uses stack repeatedly
* Return restores control flow

---

# IMPORTANT CONCEPT

Function calls are not abstract.
They are stack-based execution contexts managed at runtime.

Understanding C02 means understanding how the program "moves" through memory during execution.
