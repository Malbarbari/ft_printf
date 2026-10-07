*This activity has been created as part of the 42 curriculum by mohali.*

# ft_printf

## Description

`ft_printf` is a recreation of the standard C `printf()` function
developed as part of the 42 curriculum.

The goal of this project is to learn how variadic functions work in C
and to build a structured and extensible formatted-output function. The
project produces the static library `libftprintf.a` and supports `%c`,
`%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

``` c
int ft_printf(const char *format, ...);
```

The function returns the total number of characters printed.

## Instructions

Compile the library with:

``` sh
make
```

This creates `libftprintf.a`.

Available Makefile rules:

``` sh
make all
make clean
make fclean
make re
```

To use the library, include:

``` c
#include "ft_printf.h"
```

Example:

``` c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Name: %s | Age: %d | Hex: %x\n", "Bashar", 21, 255);
    return (0);
}
```

Compile a test program with:

``` sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Algorithm and Implementation

The implementation parses the format string one character at a time.
Normal characters are written directly. When `%` is encountered, the
following character identifies the required conversion and a conversion
dispatcher calls the appropriate helper function.

Variadic arguments are processed using `va_list`. `va_start` initializes
access to the arguments after the fixed `format` parameter, `va_arg`
retrieves the next argument using the type required by the current
conversion, and `va_end` finishes processing the argument list.

The implementation is divided into helper functions for characters,
strings, signed integers, unsigned integers, hexadecimal numbers, and
pointers. This gives each helper one clear responsibility and keeps the
main parsing logic simple and extensible.

Signed and unsigned decimal numbers are printed recursively in base 10.
The number is divided by 10 until a single digit remains, then the
digits are printed while the recursive calls return.

Hexadecimal values use the same recursive idea in base 16. The lookup
strings `0123456789abcdef` and `0123456789ABCDEF` map remainders from 0
to 15 to their lowercase or uppercase hexadecimal characters.

Pointers are handled separately from ordinary hexadecimal integers. The
implementation prints the `0x` prefix and then prints the pointer
address in hexadecimal form.

No complex data structure is required. The implementation mainly uses a
format-string pointer, a `va_list` to traverse variadic arguments, and
integer counters to track the number of printed characters.

## Resources

Resources used while studying and implementing the project:

-   The 42 `ft_printf` project subject.
-   C manual pages/documentation for `printf` and `write`.
-   Documentation for `<stdarg.h>`, including `va_list`, `va_start`,
    `va_arg`, and `va_end`.
-   Knowledge and utility-function experience gained from the Libft
    project.

### AI Usage

AI was used as a learning and review tool during the project. It was
used to explain variadic functions, recursive decimal and hexadecimal
conversion, review implementation logic and edge cases, help create
comparison tests against the standard `printf`, and help structure and
review this README.

The implementation was studied function by function so that its
behavior, design decisions, and code can be explained and reproduced
independently.
