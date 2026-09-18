# C Program Compilation Stages & AArch64 Cross Compilation

**Date:** 24-Aug-2026
**Author:** Vamsi
**Purpose:** Understanding the C compilation process, cross-compilation for AArch64, ELF binaries, symbol tables, `strip`, and `nm`.

---

## 1. C Program

### `test.c`

```c
#include <stdio.h>

#define MAX 10

int y = 20;
static int m = 100;

int main()
{
    static int m = 23;

    // this is new test program
    int x = 5;
    int a[1] = {2};

#ifdef MAX
    x += MAX;
#else
    x -= MAX;
#endif

    return 0;
}
```

### Important Points

The program contains:

* Global variable: `y`
* File-scope static variable: `m`
* Local static variable: `m`
* Automatic local variable: `x`
* Local array: `a`
* Preprocessor macro: `MAX`
* Conditional compilation using `#ifdef`

Note that the two variables named `m` are different objects because they have different scopes:

```c
static int m = 100;     // File scope

int main()
{
    static int m = 23;  // Block scope
}
```

---

# 2. C Program Compilation Stages

A C program generally passes through the following major stages:

```text
             test.c
                |
                v
       +----------------+
       | Pre-processing |
       +----------------+
                |
                v
             test.i
                |
                v
       +----------------+
       |   Compilation  |
       +----------------+
                |
                v
             test.s
                |
                v
       +----------------+
       |    Assembly    |
       +----------------+
                |
                v
             test.o
                |
                v
       +----------------+
       |     Linking    |
       +----------------+
                |
                v
              test
```

The four main stages are:

1. Pre-processing
2. Compilation / Translation
3. Assembly
4. Linking

---

# 3. Pre-Processing Stage

### Input

```text
.c
```

### Output

```text
.i
```

Example:

```text
test.c -> test.i
```

The preprocessor handles:

* Header file expansion
* Macro replacement
* Conditional compilation
* Comment removal

For example:

```c
#define MAX 10
```

and:

```c
#ifdef MAX
    x += MAX;
#else
    x -= MAX;
#endif
```

Since `MAX` is defined, the preprocessor selects:

```c
x += 10;
```

The `#else` section is removed from the resulting preprocessed source.

### Command

```bash
gcc -E test.c -o test.i
```

---

# 4. Compilation / Translation Stage

### Input

```text
.i
```

### Output

```text
.s
```

Example:

```text
test.i -> test.s
```

During this stage, the compiler performs:

* Syntax analysis
* Semantic analysis
* Type checking
* Optimization, depending on compiler options
* Generation of assembly code

If there are source-level errors, the compiler reports them during this stage.

### Command

```bash
gcc -S test.i -o test.s
```

The generated `test.s` contains architecture-specific assembly instructions.

---

# 5. Assembly Stage

### Input

```text
.s
```

### Output

```text
.o
```

Example:

```text
test.s -> test.o
```

The assembler converts assembly instructions into machine code and generates an object file.

The object file can contain:

* Machine instructions
* Data sections
* Relocation information
* Symbol information
* Section information

### Command

```bash
gcc -c test.s -o test.o
```

---

# 6. Linking Stage

### Input

```text
.o
```

### Output

```text
Executable
```

Example:

```text
test.o -> test
```

The linker performs tasks such as:

* Resolving symbols
* Linking object files
* Linking required libraries
* Resolving external functions
* Performing relocations
* Creating the final executable

For example, the program includes:

```c
#include <stdio.h>
```

which may require linking against the C library depending on what functions are used.

### Command

```bash
gcc test.o -o test
```

---

# 7. Generate All Compilation Intermediate Files

GCC provides the `--save-temps` option to keep intermediate files.

### Command

```bash
gcc --save-temps test.c -o test
```

This generates:

```text
test.c
test.i
test.s
test.o
test
```

Example:

```text
dell@dell-Latitude:~/C/test_prgm$ gcc --save-temps test.c -o test

dell@dell-Latitude:~/C/test_prgm$ ls

README.md
test
test.c
test.i
test.o
test.s
```

Therefore:

```text
test.c  -> Source file
test.i  -> Preprocessed source
test.s  -> Assembly source
test.o  -> Object file
test    -> Final executable
```

---

# 8. Native x86-64 Compilation

The host Ubuntu system can compile the program for the native x86-64 architecture using `gcc`.

### Command

```bash
gcc --save-temps test.c -o test
```

Check the generated executable:

```bash
file test
```

Output:

```text
test: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV),
dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2,
BuildID[sha1]=c09ed505e6b95de0b504263a245c8b6ee6d5dafc,
for GNU/Linux 3.2.0, not stripped
```

This tells us:

```text
ELF 64-bit
        |
        +-- Executable format

x86-64
        |
        +-- Target architecture

dynamically linked
        |
        +-- Uses dynamic libraries

not stripped
        |
        +-- Symbol information is still present
```

---

# 9. Check Executable Size

The `size` command can be used to display the sizes of important program sections.

### Command

```bash
size test
```

Example output:

```text
   text    data     bss     dec     hex filename
   1442     612       4    2058     80a test
```

### Meaning

| Section | Description                           |
| ------- | ------------------------------------- |
| `.text` | Executable machine code               |
| `.data` | Initialized global/static variables   |
| `.bss`  | Uninitialized global/static variables |
| `dec`   | Total size in decimal                 |
| `hex`   | Total size in hexadecimal             |

---

# 10. AArch64 Cross Compilation

To compile the same C program for an ARM64 / AArch64 target, use the AArch64 cross compiler.

Compiler:

```bash
aarch64-linux-gnu-gcc
```

### Command

```bash
aarch64-linux-gnu-gcc test.c -o test
```

Check the generated executable:

```bash
file test
```

Output:

```text
test: ELF 64-bit LSB pie executable, ARM aarch64, version 1 (SYSV),
dynamically linked, interpreter /lib/ld-linux-aarch64.so.1,
BuildID[sha1]=32c8cfc5909070bbeff3ea568a569dd17cc41816,
for GNU/Linux 3.7.0, not stripped
```

This confirms that the executable is built for:

```text
Architecture : ARM AArch64
Format       : ELF 64-bit
Linking      : Dynamically linked
Status       : Not stripped
```

This binary is intended for an AArch64 Linux target, not the x86-64 host system.

---

# 11. Check AArch64 Binary Size

### Command

```bash
size test
```

Output:

```text
   text    data     bss     dec     hex filename
   1819     676       4    2499     9c3 test
```

The executable contains:

```text
.text  = 1819 bytes
.data  =  676 bytes
.bss   =    4 bytes

Total  = 2499 bytes
```

---

# 12. Stripping the Executable

The `strip` utility removes symbol and debugging information that is not required for normal execution.

For AArch64:

```bash
aarch64-linux-gnu-strip
```

### Command

```bash
aarch64-linux-gnu-strip test
```

Before stripping:

```bash
file test
```

Output:

```text
test: ELF 64-bit LSB pie executable, ARM aarch64, version 1 (SYSV),
dynamically linked, interpreter /lib/ld-linux-aarch64.so.1,
BuildID[sha1]=32c8cfc5909070bbeff3ea568a569dd17cc41816,
for GNU/Linux 3.7.0, not stripped
```

After stripping:

```bash
aarch64-linux-gnu-strip test
```

Check again:

```bash
file test
```

Output:

```text
test: ELF 64-bit LSB pie executable, ARM aarch64, version 1 (SYSV),
dynamically linked, interpreter /lib/ld-linux-aarch64.so.1,
BuildID[sha1]=32c8cfc5909070bbeff3ea568a569dd17cc41816,
for GNU/Linux 3.7.0, stripped
```

The important change is:

```text
not stripped
     |
     v
stripped
```

---

# 13. Why Does `size` Show the Same Value After `strip`?

Before stripping:

```text
   text    data     bss     dec     hex filename
   1819     676       4    2499     9c3 test
```

After stripping:

```text
   text    data     bss     dec     hex filename
   1819     676       4    2499     9c3 test
```

This is expected.

The `size` command primarily reports the sizes of program sections such as:

```text
.text
.data
.bss
```

`strip` mainly removes symbol/debug information.

Therefore, the `.text`, `.data`, and `.bss` values may remain unchanged even though the overall ELF file can become smaller.

To see the actual file size, use:

```bash
ls -lh test
```

or:

```bash
stat test
```

---

# 14. Inspect Symbols Using `nm`

The `nm` command displays symbols contained in an object file or executable.

For AArch64:

```bash
aarch64-linux-gnu-nm test
```

Example output before stripping:

```text
0000000000000278 r __abi_tag
                 U abort@GLIBC_2.17
0000000000020020 B __bss_end__
000000000002001c B __bss_start
0000000000000734 t call_weak_fn
                 w __cxa_finalize@GLIBC_2.17
0000000000020000 D __data_start
0000000000020008 D __dso_handle
000000000001fd88 a _DYNAMIC
000000000000088c T _fini
0000000000000810 t frame_dummy
000000000001fd78 d __frame_dummy_init_array_entry
0000000000000990 r __FRAME_END__
000000000001ffc8 a _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000000008a4 r __GNU_EH_FRAME_HDR
0000000000000640 T _init
00000000000008a0 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 U __libc_start_main@GLIBC_2.34
0000000000020014 d m
0000000000020018 d m.0
0000000000000818 T main
0000000000000780 t register_tm_clones
                 U __stack_chk_fail@GLIBC_2.17
                 U __stack_chk_guard@GLIBC_2.17
0000000000000700 T _start
0000000000020020 D __TMC_END__
0000000000020010 D y
```

Important symbols from our program include:

```text
0000000000000818 T main
0000000000020014 d m
0000000000020018 d m.0
0000000000020010 D y
```

---

# 15. Understanding `nm` Symbol Types

Some common `nm` symbol characters are:

| Symbol    | Meaning                            |
| --------- | ---------------------------------- |
| `T`       | Global symbol in text/code section |
| `t`       | Local symbol in text/code section  |
| `D`       | Global initialized data            |
| `d`       | Local initialized data             |
| `B`       | Global uninitialized data / BSS    |
| `b`       | Local BSS symbol                   |
| `R`       | Read-only data                     |
| `r`       | Local read-only data               |
| `U`       | Undefined symbol                   |
| `W` / `w` | Weak symbol                        |

For example:

```text
T main
```

means `main` is a global text/code symbol.

And:

```text
D y
```

means `y` is a global initialized data symbol.

The two `m` symbols appear separately because the program has two different variables with the same name but different scopes:

```c
static int m = 100;

int main()
{
    static int m = 23;
}
```

---

# 16. Run `nm` After `strip`

After stripping:

```bash
aarch64-linux-gnu-strip test
```

Run:

```bash
aarch64-linux-gnu-nm test
```

Output:

```text
aarch64-linux-gnu-nm: test: no symbols
```

This demonstrates that the normal symbol table information has been removed from the stripped executable.

---

# 17. Stripped vs Unstripped Binary

| Feature             | Unstripped            | Stripped            |
| ------------------- | --------------------- | ------------------- |
| Program execution   | Yes                   | Yes                 |
| Machine code        | Present               | Present             |
| `.text`             | Present               | Present             |
| `.data`             | Present               | Present             |
| `.bss`              | Present               | Present             |
| Symbol information  | Present               | Removed/reduced     |
| Debugging           | Easier                | Difficult           |
| `nm` symbol listing | Available             | Usually unavailable |
| Deployment          | Usually not preferred | Preferred           |
| File size           | Larger                | Usually smaller     |

### General Rule

```text
Development / Debugging
        |
        v
   Unstripped Binary
        |
        +--> GDB
        +--> Symbol information
        +--> Easier debugging


Release / Deployment
        |
        v
    Stripped Binary
        |
        +--> Smaller binary
        +--> Reduced symbol information
        +--> Better suited for target deployment
```

---

# 18. Recommended Debugging Workflow

Do not overwrite your only debug binary with `strip`.

Instead, keep a debug copy:

```bash
cp test test.debug
```

Then strip the deployment binary:

```bash
aarch64-linux-gnu-strip test
```

Now:

```text
test.debug
    |
    +--> Unstripped
    +--> Use for GDB/debugging
    +--> Keep symbol information


test
    |
    +--> Stripped
    +--> Deploy to AArch64 target
    +--> Smaller/reduced symbol information
```

This is particularly useful for Embedded Linux development.

---

# 19. Complete Command Flow

## Native x86-64 Build

```bash
gcc --save-temps test.c -o test
```

Check:

```bash
file test
size test
```

---

## AArch64 Build

```bash
aarch64-linux-gnu-gcc test.c -o test
```

Check:

```bash
file test
size test
```

---

## Check Symbols

```bash
aarch64-linux-gnu-nm test
```

---

## Keep Debug Copy

```bash
cp test test.debug
```

---

## Strip Deployment Binary

```bash
aarch64-linux-gnu-strip test
```

---

## Verify

```bash
file test
size test
aarch64-linux-gnu-nm test
```

Expected result:

```text
test: ... ARM aarch64 ... stripped
```

and:

```text
aarch64-linux-gnu-nm: test: no symbols
```

---

# 20. Summary

The complete C compilation flow is:

```text
                    C SOURCE
                       |
                       |  Pre-processing
                       v
                     .i
                       |
                       |  Compilation
                       v
                     .s
                       |
                       |  Assembly
                       v
                     .o
                       |
                       |  Linking
                       v
                  EXECUTABLE
                       |
              +--------+--------+
              |                 |
         Unstripped          strip
              |                 |
              v                 v
        Debug Binary       Release Binary
              |                 |
             GDB             Target
```

For AArch64 Embedded Linux development:

```bash
aarch64-linux-gnu-gcc test.c -o test
```

creates an AArch64 executable.

Use:

```bash
aarch64-linux-gnu-nm test
```

to inspect symbols.

Use:

```bash
aarch64-linux-gnu-strip test
```

to remove symbol/debug information that is not required for normal execution.

**Key concept:**

> Keep the unstripped binary for debugging and use the stripped binary for deployment/release.

