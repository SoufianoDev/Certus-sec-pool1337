# C07 – Dynamic Memory Concepts (malloc / free)

## 1. Stack vs Heap

### Stack

```
┌─────────────────┐ ←── High address
│   main()        │
│   int a = 5     │
│   int b = 10    │
├─────────────────┤
│   func()        │ ←── Created on call
│   int x = 20    │
│   int y = 30    │
├─────────────────┤
│   ...           │
└─────────────────┘ ←── Low address (grows downward)
```

**Characteristics:**
- Automatic: created and destroyed with functions
- Fast: simple allocation (pointer move)
- Limited: fixed size (~8 MB)
- Temporary: data disappears after return

### Heap

```
┌─────────────────────────────┐
│                             │
│        Heap Memory          │  ←── Manual allocation
│                             │
│    ┌─────────────────┐      │
│    │  malloc(100)    │      │  ←── 100 bytes
│    │  (dynamic size) │      │
│    └─────────────────┘      │
│                             │
│    ┌─────────────────┐      │
│    │  malloc(50)     │      │  ←── 50 bytes
│    └─────────────────┘      │
│                             │
└─────────────────────────────┘
```

**Characteristics:**
- Manual: you control allocation and deallocation
- Large: much bigger than stack
- Persistent: data remains until freed
- Flexible: size can change (realloc)

---

## 2. malloc - Memory Allocation

### The Concept

```
Request from system: "I need 100 bytes"
          ↓
System searches heap for free space
          ↓
Returns address of first byte
          ↓
Use this address to access memory
```

### Why sizeof?

```
I want an array of 5 integers:

Wrong way: malloc(5)  ←── 5 bytes only!
Correct way: malloc(5 × sizeof(int))  ←── 20 bytes

sizeof(int) = 4 bytes (usually)
5 × 4 = 20 bytes ←── correct!
```

### Why Check for NULL?

```
malloc(1 billion bytes)  ←── may fail!
        ↓
Returns NULL
        ↓
If we use NULL → crash!

Solution:
int *p = malloc(size);
if (p == NULL) {
    // Handle error
    return;
}
```

---

## 3. free - Memory Deallocation

### The Concept

```
Done using memory → tell system "I no longer need it"
          ↓
System returns it to free memory pool
          ↓
Can be used later
```

### Memory Leak Danger

```
int *p = malloc(100);
        ↓
p = NULL;  ←── Lost the address!
        ↓
Memory is still allocated...
        ↓
...but no pointer to it!
        ↓
Cannot free it → memory leak!
```

**Result:** Over time, the program consumes more and more memory until it stops.

### Double Free Danger

```
free(p);   ←── First free
free(p);   ←── Second free!
        ↓
undefined behavior
        ↓
Program may crash unexpectedly
```

### Safe Pattern

```
free(p);
p = NULL;  ←── Make pointer "empty"
        ↓
Now p points to nothing
        ↓
free(p) again ←── Safe! (free(NULL) does nothing)
```

---

## 4. calloc - Allocation with Initialization

### Difference from malloc

| | malloc | calloc |
|---|--------|--------|
| Initialization | Random values (undefined) | Zero |
| Parameters | Single size | Count + size |
| Use | General memory | Number arrays |

```
malloc(5 × sizeof(int)):
┌─────┬─────┬─────┬─────┬─────┐
│ ??? │ ??? │ ??? │ ??? │ ??? │  ←── Random values
└─────┴─────┴─────┴─────┴─────┘

calloc(5, sizeof(int)):
┌─────┬─────┬─────┬─────┬─────┐
│  0  │  0  │  0  │  0  │  0  │  ←── Zero-initialized
└─────┴─────┴─────┴─────┴─────┘
```

---

## 5. String Duplication

### The Concept

```
Original string: "Hello" (in stack or literals)
        ↓
I want an independent copy in heap
        ↓
malloc(6)  ←── 5 chars + 1 for \0
        ↓
"Hello" in heap ←── modifiable and persistent
```

### Why Do We Need It?

- **String literals**: `char *s = "hello"` → cannot modify
- **Local strings**: `char s[] = "hello"` in function → disappears after return
- **Solution**: heap copy → remains until we delete it

### Steps:
1. Calculate string length
2. Allocate `length + 1` bytes
3. Check for NULL
4. Copy character by character
5. Add `\0`

---

## 6. Dynamic Array Creation

### The Concept

```
I want an array of numbers from min to max-1

Example: min=3, max=7
Result: [3, 4, 5, 6]

Size: max - min = 4 elements
```

### Why Use Heap?

```
// Stack (fixed)
int arr[4];  ←── Size must be known at compile time

// Heap (dynamic)
int *arr = malloc(size × sizeof(int));  ←── Size at runtime!
```

---

## 7. String Splitting

### The Concept

```
Text: "Hello,World,42"
Delimiter: ","
        ↓
Result: ["Hello", "World", "42"]
```

### Implementation

```
1. Count number of words
2. Allocate array of pointers (word_count + 1)
3. For each word:
   - Skip delimiters
   - Calculate word length
   - Allocate memory for word
   - Copy word
4. Terminate array with NULL
```

### Why "Array of Pointers"?

```
Result:
┌─────────┬─────────┬─────────┬─────────┐
│ 0x1000  │ 0x1006  │ 0x100c  │  NULL   │  ←── Array
└────┬────┴────┬────┴────┬────┴─────────┘
     ↓         ↓         ↓
   "Hello"   "World"   "42"
   (6 bytes)  (6 bytes)  (3 bytes)
```

Each word in a separate location in heap!

---

## 8. realloc - Resizing Memory

### The Concept

```
Current array: [1, 2, 3] (3 elements)
        ↓
Want to add two more: [1, 2, 3, 4, 5]
        ↓
realloc(p, 5 × sizeof(int))
        ↓
System tries:
  - Extend current space (if space available)
  - Or move data to a new larger location
```

### Why Check for NULL?

```
int *new_p = realloc(p, new_size);
if (new_p == NULL) {
    // Failed! But p is still valid
    return;
}
p = new_p;  // Now use the new pointer
```

---

## Summary

| Concept | Core Idea |
|---------|-----------|
| **Stack** | Automatic, fast, limited, temporary |
| **Heap** | Manual, large, persistent, flexible |
| **malloc** | Request memory from heap |
| **free** | Return memory to system |
| **NULL check** | Always verify allocation success |
| **NULL after free** | Make pointer empty after freeing |
| **Memory Leak** | Losing pointer before free |
| **Double Free** | Freeing same memory twice |
| **calloc** | malloc + zero initialization |
| **realloc** | Resize allocated memory |
| **Split** | Array of pointers for each word |
