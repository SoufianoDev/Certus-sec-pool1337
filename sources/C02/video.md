````md id="c02_video_final"
# 📹 C02 – Strings & Memory Manipulation (C Base)

## 🎯 Topic
C02 focuses on strings and memory traversal in C.

Core concepts:
- strings
- character arrays
- pointers
- memory traversal
- character manipulation
- null terminator (`'\0'`)

This level teaches how text is represented and manipulated inside memory.

---

# 🎥 Strings Video

[▶️ Watch Video](https://youtu.be/n3oh76pJ1eA?si=UXobZ7vWSf0cMsL7)

🖼️ Preview:
[![Strings Video](https://img.youtube.com/vi/n3oh76pJ1eA/hqdefault.jpg)](https://youtu.be/n3oh76pJ1eA?si=UXobZ7vWSf0cMsL7)

---

# 🎥 Pointers Video

[▶️ Watch Video](https://youtu.be/MIL2BK02X8A?si=8YNbDTa2dQMS70DG)

🖼️ Preview:
[![Pointers Video](https://img.youtube.com/vi/MIL2BK02X8A/hqdefault.jpg)](https://youtu.be/MIL2BK02X8A?si=8YNbDTa2dQMS70DG)

---

## 🧠 String Memory Model

``` id="9kzzmj"
'H'  'e'  'l'  'l'  'o' '\0'
 ↓    ↓    ↓    ↓    ↓    ↓
[72] [101][108][108][111][0]
````

A string in C is:

> sequential memory ending with `'\0'`

---

## 🧠 Pointer Memory Model

```id="lhm4e3"
str → first memory address
        ↓
'H' → 'e' → 'l' → 'l' → 'o'
```

Pointers are used to navigate memory directly.

---

## ⚠️ Key Idea

C02 teaches:

> strings are memory blocks and pointers are the way to access them

```
```
