<div align="center">

<img src="assets/pool_1337.png" alt="Pool 1337" width="600">

# 🏊 Pool 1337

**A structured journey through C & Shell Programming**

*1337 / 42 Network — Piscine*

[![C](https://img.shields.io/badge/C-%2300599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Shell](https://img.shields.io/badge/Bash-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white)](https://www.gnu.org/software/bash/)
[![School](https://img.shields.io/badge/1337%20%2F%2042-black?style=for-the-badge&logo=42&logoColor=white)](https://1337.ma/)
[![Norm](https://img.shields.io/badge/Norminette-Compliant-brightgreen?style=for-the-badge&logo=c&logoColor=white)](https://github.com/42School/norminette)

</div>

---

## 📌 Overview

This repository documents my progression through the **1337 / 42 Piscine** — an intensive coding bootcamp built around low-level systems programming. Every exercise, rush project, and exam in this repo is a step toward mastering C and Shell from scratch under strict constraints.

> **No copy-paste. No shortcuts. Just clean code, pointers, and pressure.**

**Author:** `sabir` | **School:** 1337 / 42 Network | **Created:** May 2026

---

## 📁 Repository Structure

```
📦 pool1337/
│
├── 📄 README.md                 # This file
├── 🖼️ assets/
│   └── pool_1337.png            # Project banner (~800KB)
│
├── 📂 days/                     # Daily exercises (C00-C07)
│   ├── 💠 C00/                  # Basic syntax, loops, output
│   │   ├── ex00/ ft_putchar.c
│   │   ├── ex01/ ft_print_alphabet.c
│   │   ├── ex02/ ft_print_reverse_alphabet.c
│   │   ├── ex03/ ft_print_numbers.c
│   │   ├── ex04/ ft_is_negative.c
│   │   ├── ex05/ ft_print_comb.c
│   │   ├── ex06/ ft_print_comb2.c
│   │   ├── ex07/ ft_putnbr.c
│   │   └── ex08/ ft_print_combn.c
│   │
│   ├── 💠 C01/                  # Pointers & arrays
│   │   ├── ex00/ ft_ft.c
│   │   ├── ex01/ ft_ultimate_ft.c
│   │   ├── ex02/ ft_swap.c
│   │   ├── ex03/ ft_div_mod.c
│   │   ├── ex04/ ft_ultimate_div_mod.c
│   │   ├── ex05/ ft_putstr.c
│   │   ├── ex06/ ft_strlen.c
│   │   ├── ex07/ ft_rev_int_tab.c
│   │   └── ex08/ ft_sort_int_tab.c
│   │
│   ├── 💠 C02/                  # String manipulation (13 exercises)
│   │   ├── ex00/ ft_strcpy.c
│   │   ├── ex01/ ft_strncpy.c
│   │   ├── ex02/ ft_str_is_alpha.c
│   │   ├── ex03/ ft_str_is_numeric.c
│   │   ├── ex04/ ft_str_is_lowercase.c
│   │   ├── ex05/ ft_str_is_uppercase.c
│   │   ├── ex06/ ft_str_is_printable.c
│   │   ├── ex07/ ft_strupcase.c
│   │   ├── ex08/ ft_strlowcase.c
│   │   ├── ex09/ ft_strcapitalize.c
│   │   ├── ex10/ ft_strlcpy.c
│   │   ├── ex11/ ft_putstr_non_printable.c
│   │   └── ex12/ ft_print_memory.c
│   │
│   ├── 💠 C03/                  # Advanced string functions
│   │   ├── ex00/ ft_strcmp.c
│   │   ├── ex01/ ft_strncmp.c
│   │   ├── ex02/ ft_strcat.c
│   │   ├── ex03/ ft_strncat.c
│   │   ├── ex04/ ft_strstr.c
│   │   └── ex05/ ft_strlcat.c
│   │
│   ├── 💠 C04/                  # Base conversion & atoi
│   │   ├── ex00/ ft_strlen.c
│   │   ├── ex01/ ft_putstr.c
│   │   ├── ex02/ ft_putnbr.c
│   │   ├── ex03/ ft_atoi.c
│   │   ├── ex04/ ft_putnbr_base.c
│   │   └── ex05/ ft_atoi_base.c
│   │
│   ├── 💠 C05/                  # Recursion & math
│   │   ├── ex00/ ft_iterative_factorial.c
│   │   ├── ex01/ ft_recursive_factorial.c
│   │   ├── ex02/ ft_iterative_power.c
│   │   ├── ex03/ ft_recursive_power.c
│   │   ├── ex04/ ft_fibonacci.c
│   │   ├── ex05/ ft_sqrt.c
│   │   ├── ex06/ ft_is_prime.c
│   │   ├── ex07/ ft_find_next_prime.c
│   │   └── ex08/ ft_ten_queens_puzzle.c
│   │
│   ├── 💠 C06/                  # Program arguments (argc/argv)
│   │   ├── ex00/ ft_print_program_name.c
│   │   ├── ex01/ ft_print_params.c
│   │   ├── ex02/ ft_rev_params.c
│   │   └── ex03/ ft_sort_params.c
│   │
│   └── 💠 C07/                  # Dynamic memory (malloc/free)
│       ├── ex00/ ft_strdup.c
│       ├── ex01/ ft_range.c
│       ├── ex02/ ft_ultimate_range.c
│       ├── ex03/ ft_strjoin.c
│       ├── ex04/ ft_convert_base.c
│       └── ex05/ ft_split.c
│
├── 📂 sources/                  # Educational resources
│   ├── C00/                     # Variables, conditions, loops, syscalls
│   │   ├── notes.md             # Deep dive into C fundamentals
│   │   └── video.md             # Tutorial links
│   ├── C01/                     # Pointer arithmetic deep dive
│   │   ├── notes.md
│   │   └── video.md
│   ├── C02/                     # String operations theory
│   │   ├── notes.md
│   │   └── video.md
│   ├── C03/                     # String comparison logic
│   │   ├── notes.md
│   │   └── video.md
│   ├── C04/                     # Base conversion algorithms
│   │   ├── notes.md
│   │   └── video.md
│   ├── C05/                     # Recursion, Big O, complexity
│   │   ├── notes.md             # Recursion trees, stack depth, memoization
│   │   └── video.md
│   ├── C06/                     # Command-line arguments
│   │   ├── notes.md
│   │   └── video.md
│   ├── C07/                     # Memory management
│   │   ├── notes.md
│   │   └── video.md
│   ├── C08/                     # Structs & headers (planned)
│   │   ├── notes.md
│   │   └── video.md
│   ├── C09/                     # Libraries & Makefiles (planned)
│   │   ├── notes.md
│   │   └── video.md
│   ├── C10/                     # File I/O (planned)
│   ├── C11/                     # Function pointers (planned)
│   ├── C12/                     # Linked lists (planned)
│   └── C13/                     # Binary trees (planned)
│
├── 📂 EXAM/                     # Exam preparations
│   └── level00/                 # Foundation level (6 exercises)
│       ├── aff_a/
│       ├── aff_first_param/
│       ├── aff_last_param/
│       ├── ft_countdown/
│       ├── maff_alpha/
│       └── rot_13/
│
└── 🛠️ tools/                     # Development tools
    ├── 42header/                # Vim plugin for 42 header
    │   ├── plugin/
    │   ├── img/
    │   ├── set_header.sh
    │   ├── README.md
    │   └── LICENSE
    ├── mini-moulinette/         # Automated testing suite
    └── norminette/              # 42 coding style checker
```

---

## 📚 Curriculum Details

### 🐚 Shell Modules (Planned)
| Module | Topics | Status |
|--------|--------|--------|
| **Shell00** | File system navigation, basic commands, git basics | 🔴 Not started |
| **Shell01** | Permissions, symbolic links, scripts, automation | 🔴 Not started |

### 💠 C Modules
| Module | Topics | Exercises | Status |
|--------|--------|-----------|--------|
| **C00** | `write()`, loops, basic output | 9 | ✅ Complete |
| **C01** | Pointers, pointer arithmetic, arrays | 9 | ✅ Complete |
| **C02** | `ft_strcpy`, `ft_strlen`, string basics | 13 | ✅ Complete |
| **C03** | `ft_strcat`, `ft_strcmp`, string comparisons | 6 | ✅ Complete |
| **C04** | `ft_itoa`, base conversion, `atoi` | 6 | ✅ Complete |
| **C05** | Recursion, Fibonacci, power, square root | 9 | ✅ Complete |
| **C06** | `argc`/`argv`, program arguments | 4 | ✅ Complete |
| **C07** | `malloc`, `free`, dynamic memory | 6 | ✅ Complete |
| **C08** | Structs, header files, include guards | — | 🟡 Planned |
| **C09** | Static libraries, `ar`, `Makefile` | — | 🟡 Planned |
| **C10** | File I/O operations | — | 🟡 Planned |
| **C11** | Function pointers | — | 🟡 Planned |
| **C12** | Linked lists | — | 🟡 Planned |
| **C13** | Binary trees | — | 🟡 Planned |

### 👥 Rush Projects (Planned)
| Project | Description | Status |
|---------|-------------|--------|
| **Rush00** | Weekend team project — collaborative problem solving | 🔴 Not started |
| **Rush01** | Advanced teamwork under time pressure | 🔴 Not started |

### ⏱️ Exams
| Exam | Description | Status |
|------|-------------|--------|
| **level00** | Foundation test (6 exercises) | ✅ Available |
| **level01** | Core skills assessment | 🔴 Planned |
| **level02** | Intermediate challenges | 🔴 Planned |
| **level03** | Final evaluation | 🔴 Planned |

---

## 🎯 Learning Goals

- [x] Master low-level programming in C
- [x] Deeply understand pointers & memory management
- [x] Implement standard library functions from scratch
- [x] Write clean, readable, constraint-respecting code
- [x] Develop algorithmic thinking under pressure
- [ ] Collaborate effectively on team rush projects *(pending)*
- [x] Follow **Norminette** standards strictly

---

## ⚙️ Code Standards

All code in this repository follows the **42 Norm (Norminette)**:

| Rule | Constraint |
|------|------------|
| Function length | ≤ 25 lines |
| Variables per function | ≤ 5 |
| Loop type | `while` only (no `for`) |
| Assignments in conditions | ❌ Forbidden |
| Memory leaks | ❌ Zero tolerance |

```bash
# Check norm compliance
norminette file.c

# Compile with strict warnings
cc -Wall -Wextra -Werror file.c

# Run with valgrind for leak detection
valgrind --leak-check=full ./a.out
```

---

## 🛠️ Dev Stack

| Tool | Usage |
|------|-------|
| **C** | Primary programming language |
| **GCC** | Compilation with strict flags (`-Wall -Wextra -Werror`) |
| **Bash** | Shell scripting modules |
| **Vim** | Main editor (as required by the school) |
| **Git** | Version control & submission |
| **Valgrind** | Memory leak detection |
| **Norminette** | Code style enforcement |

---

## 📈 Progress Timeline

```
🌱 Day 1     → "What even is a pointer?"
💡 Week 1    → "Oh. The address of a variable. Got it."
🔁 Week 2    → "malloc makes sense now"
✨ Week 3    → "Recursion = a function calling itself. Magic."
👥 Rush      → "Teamwork hits different at 3am" *(pending)*
⏱️  Exam      → "I think in C now" *(in progress)*
🚀 End       → "Ship it." *(pending)*
```

**Current Status:** C00-C07 completed | 62 exercises solved | 6 exam exercises prepared

---

## 📊 Repository Stats

| Metric | Value |
|--------|-------|
| **Total Exercises** | 62+ (C00-C07) |
| **Lines of Code** | ~2,500+ |
| **Educational Notes** | ~30,000+ words (sources/) |
| **Exam Exercises** | 6 (level00) |
| **Tools Included** | 3 (42header, moulinette, norminette) |
| **PDF Subjects** | 7 (c00.pdf through c07.pdf) |

---

## 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/Baktrack-sec/pool1337.git
cd pool1337

# Navigate to any exercise
cd days/C00/ex00

# Compile
gcc -Wall -Wextra -Werror ft_putchar.c

# Run
./a.out

# Check norm
norminette ft_putchar.c

# Check for leaks
valgrind --leak-check=full ./a.out
```

---

## 📖 Educational Resources

Each module in `sources/` contains:
- **`notes.md`** — Deep theoretical explanations
- **`video.md`** — Curated tutorial links

**Example from C05 notes:**
> Recursion is not just a programming technique; it is a mathematical structure that maps directly to inductive definitions. Every recursive call creates a new stack frame, and understanding stack depth is critical to avoiding overflow.

---

## ⚠️ Known Issues

| Issue | Location | Status |
|-------|----------|--------|
| `ft_strdup` allocates 0 bytes | `days/C07/ex00/` | 🔴 Needs fix |
| `free()` after `return` (unreachable) | `days/C07/ex00/` | 🟡 Needs cleanup |
| Vim `.swp` file committed | `days/C04/ex00/` | 🟡 Add to `.gitignore` |
| C08-C13 not implemented | `days/` | 🟡 In progress |
| Shell modules not started | `days/` | 🔴 Planned |
| Rush projects not started | `days/` | 🔴 Planned |

---

## 🤝 Contributing

This is a personal learning repository, but suggestions and improvements are welcome:

1. Fork the repository
2. Create a feature branch
3. Ensure Norminette compliance
4. Submit a pull request

---

## 📜 License

> ⚠️ For **educational and personal learning** purposes only.
> Not intended for commercial use or direct copying in Piscine submissions.

---

<div align="center">

**Keep pushing. Keep compiling. Keep growing.**

`cc -Wall -Wextra -Werror *.c && ./a.out`

*"Code is poetry written in logic."*

</div>
