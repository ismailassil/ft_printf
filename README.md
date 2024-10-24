---
# ft_printf - 42cursus

## Introduction

**ft_printf** is a project from the **42cursus** that involves creating a custom version of the `printf` function in C. This project helps to deepen your understanding of variadic functions, string manipulation, and formatted output. The goal is to replicate the functionality of `printf` while supporting several commonly used format specifiers, with a focus on handling edge cases and optimizing performance.

## Project Requirements

The following format specifiers should be supported:
- `%c` : Character
- `%s` : String
- `%p` : Pointer (in hexadecimal format)
- `%d` / `%i` : Signed integer
- `%u` : Unsigned integer
- `%x` / `%X` : Hexadecimal (lowercase / uppercase)
- `%%` : Percent sign

The behavior should mirror that of the standard `printf` function as closely as possible, including proper handling of edge cases like null strings and invalid specifiers.

## Learning Objectives

The goal of the **ft_printf** project:
- Understand how variadic functions work (using `va_start`, `va_arg`, and `va_end` macros).
- Improve your skills in string manipulation and formatting.
- Gain experience in handling complex output requirements, including padding, width, precision, and different format types.
- Develop a deeper understanding of low-level memory management in C.

## Features

- Custom implementation of `printf`.
- Supports multiple format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
- Handles width and precision for most specifiers.
- Works with both `int`, `unsigned int`, and `long` types.
- Efficient memory and error management.

## Usage

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ismailassil/ft_printf.git
   cd ft_printf
   ```

2. **Compile the project:**
   Use the provided Makefile to compile the library.
   ```bash
   make
   ```

3. **Include ft_printf in your projects:**
   After compiling, you will get a `libftprintf.a` file. You can include it in your project as a static library.

   Example of usage:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       ft_printf("Hello, %s!\n", "world");
       ft_printf("The number is %d\n", 42);
       return 0;
   }
   ```

4. **Run the example:**
   Compile your program with the `ft_printf` library:
   ```bash
   gcc main.c -L. -lftprintf -o program
   ./program
   ```

## Example

Here’s a simple example demonstrating **ft_printf**:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Integer: %d\n", 42);
    ft_printf("Unsigned Integer: %u\n", 3000000000U);
    ft_printf("Hexadecimal (lowercase): %x\n", 255);
    ft_printf("Hexadecimal (uppercase): %X\n", 255);
    ft_printf("Percentage: %%\n");

    return 0;
}
```

This README provides an overview of the project’s purpose, features, setup instructions, and how to use the library. Feel free to adapt the file structure or any specific sections to match your implementation.
