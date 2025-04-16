Here’s a `README.md` file you can use to explain **how to create and run `.l` and `.y` programs using PuTTY** on a remote Linux system.

---

````markdown
# Running Lex (.l) and Yacc (.y) Programs Using PuTTY

This guide walks you through how to create, compile, and run Lex and Yacc programs on a remote Linux system via **PuTTY**.

---

## 🧰 Prerequisites

- A remote Linux server (Ubuntu/Debian-based)
- PuTTY installed on your Windows machine
- Lex (Flex), Yacc (Bison), and GCC installed on the server

---

## ⚙️ Step 1: Connect via PuTTY

1. Open PuTTY.
2. Enter the IP address or hostname of your server.
3. Login with your **username** and **password** or **SSH key**.

---

## 🛠️ Step 2: Install Required Tools (One-time Setup)

Run these commands on the server:

```bash
sudo apt update
sudo apt install flex bison build-essential -y
```
````

---

## 📁 Step 3: Create Your Lex and Yacc Files

Use any command-line text editor (like `nano` or `vim`):

```bash
nano lex.l
```

Paste your Lex code and save (`Ctrl + O`, then `Enter`, then `Ctrl + X` to exit).

```bash
nano parser.y
```

Paste your Yacc code and save similarly.

---

## 🧪 Step 4: Compile and Run the Program

### 1. Generate Parser from `.y` (Yacc/Bison):

```bash
bison -d parser.y
```

This creates:

- `y.tab.c` (parser code)
- `y.tab.h` (token definitions)

### 2. Generate Scanner from `.l` (Lex/Flex):

```bash
flex lex.l
```

This creates:

- `lex.yy.c` (scanner code)

### 3. Compile Both Together:

```bash
gcc -o parser y.tab.c lex.yy.c -lfl
```

### 4. Run the Program:

```bash
./parser
```

Then type your inputs (e.g., math expressions or variable assignments):

```
a = 5
b = 3
a + b * 2
```

Use `Ctrl + D` to exit input (if required).

---

## 📌 Notes

- Make sure tokens in `.l` match those declared in `.y`.
- If you reference `yytext` in `.l`, you may need to convert characters to indices (e.g., `yytext[0] - 'a'`).

---

## 🧼 Cleanup

To delete generated files:

```bash
rm y.tab.* lex.yy.c parser
```

---

## ✅ Example File Names

- `lex.l` → Lex rules (tokens)
- `parser.y` → Yacc grammar (rules)

You can change the names, but remember to adjust commands accordingly.

---

Happy parsing! 🎉

```

---

Let me know if you want me to include a working example `.l` and `.y` pair with this!


gcc -o lexer lex.yy.c -lfl


```
