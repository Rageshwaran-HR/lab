To run `.l`, `.y`, or `.c` files via PuTTY (assuming you're working on a Linux-based system like Ubuntu, Debian, or CentOS), you need to follow these steps:

### For `.l` files (Lex files):

1. **Install Lex (Flex)**:
   First, ensure that Flex (or Lex) is installed on your system:

   ```bash
   sudo apt-get install flex  # On Ubuntu/Debian
   sudo yum install flex      # On CentOS/RedHat
   ```

2. **Generate C Code**:
   Use `flex` to compile the `.l` file:

   ```bash
   flex your_file.l
   ```

3. **Compile the C Code**:
   The above step will create a `lex.yy.c` file. Now, compile this file with a C compiler like `gcc`:

   ```bash
   gcc lex.yy.c -o your_program -lfl
   ```

4. **Run the Program**:
   After compilation, you can run the program like any other:
   ```bash
   ./your_program
   ```

### For `.y` files (Yacc files):

1. **Install Bison (GNU Yacc)**:
   Make sure Bison is installed:

   ```bash
   sudo apt-get install bison  # On Ubuntu/Debian
   sudo yum install bison      # On CentOS/RedHat
   ```

2. **Generate C Code**:
   Use `bison` to process the `.y` file:

   ```bash
   bison -d your_file.y
   ```

3. **Compile the C Code**:
   This will generate `y.tab.c` and `y.tab.h`. Compile the C code with `gcc`:

   ```bash
   gcc y.tab.c -o your_program -ly
   ```

4. **Run the Program**:
   Finally, you can run the program:
   ```bash
   ./your_program
   ```

### For `.c` files (C Code):

1. **Compile the C File**:
   If you have a C file (`your_file.c`), use `gcc` to compile it:

   ```bash
   gcc your_file.c -o your_program
   ```

2. **Run the Program**:
   After compiling, run the executable:
   ```bash
   ./your_program
   ```

### General Notes:

- You need to have the necessary tools installed (`gcc`, `flex`, `bison`, etc.).
- Ensure you have the correct permissions to run the files. If you encounter permission errors, you can use `chmod` to grant execution rights:
  ```bash
  chmod +x your_program
  ```

Let me know if you need help with any specific file!
