
# C07 – Dynamic Memory (malloc / free)

## Introduction
C07 is about manual memory management in C. Unlike previous topics where memory is automatic (stack), here you control memory at runtime using the heap.

---

## 1. HEAP MEMORY

- Memory allocated during program execution
- Controlled manually by the programmer
- Must be freed explicitly

---

## 2. malloc (Memory Allocation)

```c
#include <stdlib.h>

int *p = malloc(sizeof(int));
````

### Behavior:

* Allocates memory on the heap
* Returns a pointer to that memory
* Content is undefined (garbage values)

---

## 3. calloc

```c
int *p = calloc(5, sizeof(int));
```

### Difference from malloc:

* Allocates memory for multiple elements
* Initializes memory to zero

---

## 4. free

```c
free(p);
```

### Purpose:

* Releases allocated heap memory
* Prevents memory leaks

---

## 5. MEMORY LIFETIME

| Type  | Lifetime                   |
| ----- | -------------------------- |
| Stack | automatic (function scope) |
| Heap  | manual (until free)        |

---

## 6. MEMORY LEAK

```c
int *p = malloc(10);
p = NULL; // lost reference → memory leak
```

Problem:

* Memory still allocated
* No way to free it

---

## 7. DOUBLE FREE (ERROR)

```c
free(p);
free(p); // invalid
```

Result:

* Undefined behavior
* Program crash possible

---

## 8. REAL USAGE PATTERN

```c
int *arr = malloc(5 * sizeof(int));

if (!arr)
    return 1;

arr[0] = 10;
arr[1] = 20;

free(arr);
```

---

## 9. WHY HEAP EXISTS

* Stack is limited
* Heap allows dynamic size
* Needed for:

  * arrays with runtime size
  * data structures (linked lists, trees)

---

## 10. CORE CONCEPT

C07 introduces full manual control over memory.

You are responsible for:

* allocation
* usage
* deallocation

---

## CORE SUMMARY

* malloc → allocate memory
* calloc → allocate + zero initialize
* free → release memory
* heap → dynamic memory region
* errors → leak, double free, invalid access

```
```
