````ذذذذذذة
# C – argc & argv (Command Line Arguments)

This section explains how a C program receives input from the command line using `argc` and `argv`.

---

# 1. PROGRAM ENTRY POINT

In C, the `main` function can receive external input:

```c
int main(int argc, char **argv)
````

### Definitions

* `argc` → number of arguments passed to the program
* `argv` → array of strings containing the arguments

---

# 2. BASIC EXECUTION MODEL

When you run a program like:

```
./program hello 42
```

The operating system transforms it into:

* argc = 3
* argv = ["./program", "hello", "42"]

---

## Argument breakdown

```
argv[0] → program name
argv[1] → "hello"
argv[2] → "42"
```

---

# 3. ARGUMENT STRUCTURE (Memory Model)

`argv` is an array of pointers to null-terminated strings.

Conceptually:

```
argv → [ * ] [ * ] [ * ]
        ↓     ↓     ↓
       "a"   "b"   "c"
```

Each element points to a string in memory.

---

# 4. argc RULES

* Always `argc >= 1`
* `argv[0]` is always the program name
* Last valid index is `argc - 1`

Important invariant:

```
argv[argc] = NULL
```

---

# 5. argv CHARACTERISTICS

* Type: `char **`
* Represents an array of strings
* Each argument is a C string (`char *`)
* Strings are null-terminated (`'\0'`)

---

# 6. SAFE ACCESS PATTERN

Before accessing `argv[i]`, always validate `argc`:

```c
if (argc > 1)
    printf("%s\n", argv[1]);
```

Without validation → undefined behavior (segfault risk)

---

# 7. TYPICAL PARSING FLOW

Command-line input processing usually follows:

1. Read `argc/argv`
2. Validate argument count
3. Validate argument format
4. Convert strings if needed
5. Execute program logic

---

# 8. STRING TO INTEGER (MANUAL CONCEPT)

C does not auto-convert strings to numbers.

A simplified conversion model:

```c
int result = result * 10 + (str[i] - '0');
```

---

## Core idea

* Characters are ASCII values
* Digits are contiguous in ASCII

Example:

```
'0' = 48
'1' = 49
```

So:

```
digit = str[i] - '0'
```

---

# 9. INPUT VALIDATION RULES

Before converting or using arguments:

* check if characters are digits
* handle signs (+ / -)
* reject invalid formats if required

Example condition:

```
(c >= '0' && c <= '9')
```

---

# 10. EDGE CASES

Typical cases you must consider:

* Leading spaces: "   42"
* Positive sign: "+42"
* Negative sign: "-42"
* Mixed input: "42abc"
* Empty string: ""

Behavior depends on specification (strict vs permissive parsing)

---

# 11. PROGRAM I/O MODEL

Standard flow:

```
Input (argv)
    ↓
Validation
    ↓
Parsing / Conversion
    ↓
Processing
    ↓
Output (stdout / stderr)
```

---

# 12. STDOUT vs STDERR

C distinguishes output streams:

* stdout → normal output
* stderr → error output

Example:

```c
write(1, "OK\n", 3);
write(2, "ERROR\n", 6);
```

---

# CORE SUMMARY

* `argc` = number of arguments
* `argv` = array of argument strings
* `argv[0]` = program name
* `argv` always ends conceptually with NULL
* all inputs are raw strings
* manual parsing is required for numeric data
* validation is mandatory before usage

---

# KEY CONCEPT

C programs never receive typed input.

All arguments are raw text and must be interpreted manually using parsing logic.

```
```
