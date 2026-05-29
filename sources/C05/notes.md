# C05 – Recursion, Algorithms and Complexity (C Language)

C05 extends previous concepts by focusing on algorithmic thinking, recursion depth, and time/space complexity analysis. The goal is to understand not only how code runs, but how efficient it is.

---

# 1. RECURSION RECAP

Recursion is a function that calls itself until a stopping condition is met.

```c
int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}
```

### Key idea

Every recursive call creates a new stack frame.

---

# 2. RECURSION TREE

Example: fact(4)

```
fact(4)
 └── fact(3)
      └── fact(2)
           └── fact(1)
```

### Unwinding phase

```
fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2
fact(4) = 4 * 6
```

---

# 3. STACK DEPTH

Each recursive call consumes stack memory.

### Risk

If no base case exists:

```c
void f()
{
    f();
}
```

Result:

* infinite calls
* stack overflow

---

# 4. BASE CASE (CRITICAL CONCEPT)

Every recursive function MUST have a stopping condition.

```c
if (n <= 1)
    return 1;
```

Without it, recursion becomes infinite.

---

# 5. TIME COMPLEXITY (BIG O NOTATION)

Time complexity measures how execution time grows with input size.

---

## Constant time

O(1)

```c
return a + b;
```

Execution does not depend on input size.

---

## Linear time

O(n)

```c
for (int i = 0; i < n; i++)
    ;
```

Execution grows proportionally with n.

---

## Quadratic time

O(n²)

```c
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        ;
```

Nested loops increase cost significantly.

---

# 6. RECURSION COMPLEXITY

### Factorial

```c
fact(n)
```

* Time: O(n)
* Space: O(n) (stack calls)

---

### Fibonacci (naive)

```c
fib(n) = fib(n-1) + fib(n-2)
```

### Complexity problem

* Repeated computations
* Exponential growth

Time complexity: O(2^n)

---

# 7. OPTIMIZATION IDEA

### Memoization (concept)

Store computed results to avoid recomputation.

Result:

* reduces exponential recursion to linear

---

# 8. SPACE COMPLEXITY

Measures memory usage during execution.

Examples:

* recursion → uses stack memory
* arrays → fixed memory
* dynamic allocation → heap memory

---

# 9. ITERATION VS RECURSION

## Iteration

* uses loops
* constant stack usage
* usually more efficient

## Recursion

* cleaner logic
* uses stack per call
* risk of overflow

---

# 10. ALGORITHM THINKING MODEL

Every program can be analyzed as:

Input → Processing → Output

But complexity defines cost of processing.

---

# 11. MATHEMATICS IN C (ARITHMETIC AND NUMERIC BEHAVIOR)

C does not implement symbolic mathematics. It performs direct arithmetic operations on primitive types.

---

## 11.1 INTEGER ARITHMETIC

```c
int a = 10;
int b = 3;
```

Operations:

* Addition: a + b
* Subtraction: a - b
* Multiplication: a * b
* Division: a / b (integer division)
* Modulo: a % b (remainder)

### Important behavior

Integer division truncates the decimal part:

```c
10 / 3 = 3
```

---

## 11.2 TYPE IMPACT ON RESULTS

```c
5 / 2      -> 2
5.0 / 2    -> 2.5
```

Result depends entirely on operand types.

---

## 11.3 FLOATING POINT ARITHMETIC

```c
float x = 3.14;
double y = 3.1415926535;
```

* float: lower precision
* double: higher precision

Floating-point operations are approximations, not exact values.

---

## 11.4 STANDARD MATH LIBRARY

C provides mathematical functions via `<math.h>`.

Common functions:

* sqrt(x)
* pow(a, b)
* fabs(x)
* ceil(x)
* floor(x)

These operate on floating-point values.

---

## 11.5 MODULO AND ALGORITHMS

Modulo is fundamental in algorithmic logic:

* Even/odd check: n % 2
* Cyclic indexing
* Hashing basics

---

## 11.6 NUMERIC LIMITS AND OVERFLOW

C types have fixed limits.

```c
int x = 2147483647;
x = x + 1;
```

This causes integer overflow, leading to undefined behavior or wrap-around depending on the system.

---

## 11.7 COMPUTATIONAL MODEL

All arithmetic in C is executed at CPU level:

* Integer operations are exact within limits
* Floating-point operations are approximations
* Results depend on hardware representation (IEEE 754)

---

# 12. RECURSION AND MATHEMATICAL THINKING MODEL

Recursion in C is not only a programming technique; it is a mathematical structure that maps directly to inductive definitions.

---

## 12.1 RECURSION AS MATHEMATICAL INDUCTION

A recursive function follows the same logic as mathematical induction:

1. Base case (initial condition)
2. Recursive step (reduction toward base case)

Example:

Factorial definition:

* fact(0) = 1
* fact(n) = n × fact(n-1)

This is a direct translation of inductive math into computation.

---

## 12.2 RECURSION AS FUNCTION DECOMPOSITION

Any recursive problem is:

* A large problem
* Reduced into smaller identical subproblems

Example:

```c
fact(5)
= 5 * fact(4)
= 5 * 4 * fact(3)
...
```

This is called problem reduction.

---

## 12.3 MATHEMATICAL VIEW OF STACK

Each recursive call represents a mathematical state:

fact(n) depends on fact(n-1)

So execution is a dependency chain:

f(n) → f(n-1) → f(n-2) → ... → f(1)

This forms a linear recurrence.

---

## 12.4 RECURSIVE TIME COMPLEXITY THINKING

Mathematical reasoning of recursion depends on recurrence relations:

* T(n) = T(n-1) + O(1) → O(n)
* T(n) = 2T(n-1) → O(2^n)

Understanding recursion means solving recurrence equations.

---

## 12.5 MATHEMATICAL MODELING IN C

C recursion reflects mathematical functions:

* Factorial → product series
* Fibonacci → recurrence relation
* GCD → Euclidean algorithm

Example (GCD):

```c
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
```

This is Euclidean algorithm in recursive form.

---

## 12.6 THINKING PARADIGM

To solve problems in C05:

1. Translate problem into mathematical recurrence
2. Define base case
3. Define reduction rule
4. Analyze complexity

---

# CORE SUMMARY (C05)

* Recursion = self-calling functions
* Each call uses stack memory
* Base case prevents infinite execution
* Big O describes performance scaling
* O(1), O(n), O(n²), O(2^n) are key patterns
* Space complexity includes stack usage

---

# IMPORTANT CONCEPT

Correct code is not enough.
Efficient code depends on understanding how execution scales with input size and how memory is consumed during runtime.
