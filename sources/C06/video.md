````md id="c06_two_videos"
# 📘 C06 – argc & argv (Command Line Arguments)

## 🎯 Topic
C06 focuses on how a program receives input directly from the command line when it starts.

Core idea:
> The OS passes arguments to the program through `argc` and `argv`.

---

# 🎥 Video 1 – argc & argv Basics

[▶️ Watch Video](https://youtu.be/AwoA3EPOxM4)

🖼️ Preview:
[![argc argv](https://img.youtube.com/vi/AwoA3EPOxM4/hqdefault.jpg)](https://youtu.be/AwoA3EPOxM4)

---

## 🧠 Core Concept

```text
int main(int argc, char **argv)
````

---

## 🧾 Meaning

* `argc` → number of arguments
* `argv` → array of strings (arguments)

```text
./program hello 42
   ↓        ↓    ↓
 argv[0]  argv[1] argv[2]
```

---

# 🎥 Video 2 – Parameters & Arguments

[▶️ Watch Video](https://youtu.be/D33u0pGBChk)

🖼️ Preview:
[![parameters arguments](https://img.youtube.com/vi/D33u0pGBChk/hqdefault.jpg)](https://youtu.be/D33u0pGBChk)

---

## 🧠 Core Concept

```text
parameter = function definition input
argument  = real value passed at call time
```

---

## 🔁 Example

```c
int add(int a, int b)   // parameters
{
    return a + b;
}

add(2, 3);              // arguments
```

---

## ⚙️ Execution Model

```text
call function → pass arguments → parameters receive values → execute
```

---

## ⚠️ Key Idea

C06 teaches:

> programs receive external input either from the terminal (argc/argv) or from function calls (parameters/arguments)

```
::contentReference[oaicite:0]{index=0}
```
