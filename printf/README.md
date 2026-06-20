*This project has been created as part of the 42 curriculum by maguzman.*

# Description

Write a library that contains ft_printf(), a function that will mimic the original printf().

You can only use the following functions: malloc, free, write,va_start, va_arg, va_copy, va_end

Extra requirements:
• Do not implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

## man 3 printf

The functions in the printf() family produce output according to a format as described below.

All of these functions write the output under the control of a format string that specifies how subsequent arguments  (or  arguments  accessed  via the variable-length argument facilities of stdarg(3)) are converted for output.

Agument list of the desired argument, indexed starting from 1.  Thus,

           printf("%*d", width, num);

       and

           printf("%2$*1$d", width, num);

are equivalent.  The second style allows repeated references to the same argument.  The C99 standard does  not include  the style using '$', which comes from the Single UNIX Specification.  If the style using '$' is used, it must be used throughout for all conversions taking an argument and all width and precision  arguments,  but it  may  be mixed with "%%" formats, which do not consume an argument.  There may be no gaps in the numbers of arguments specified using '$'; for example, if arguments 1 and 3 are specified, argument 2 must also be specified somewhere in the format string.

For  some  numeric  conversions  a radix character ("decimal point") or thousands' grouping character is used. The actual character used depends on the LC_NUMERIC part of the locale.  (See setlocale(3).)  The POSIX locale uses '.' as radix character, and does not have a grouping character.  Thus,

           printf("%'.2f", 1234567.89);

results in "1234567.89" in the POSIX locale, in "1234567,89" in the nl_NL locale, and in "1.234.567,89" in the da_DK locale.


RETURN VALUE
Upon successful return, these functions return the number of characters printed (excluding the null byte used to end output to strings).

If the output was truncated due to this limit, then the return value is the number  of  characters  (excluding  the terminating null byte) which would have been written to the final string if enough space had been available.  Thus, a return value of size or more means that the output was truncated.  

If an output error is encountered, a negative value is returned.

## Variadic function macros

1. va_list ap; // argument pointer object that points to the first argument which is the *format
2. va_start(ap, format); // ap is now point to the real first argument 
3. va_end(ap); // frees the object created

## Type promotion
Automatic conversion of a lower-ranking data type to a higher-ranking data type when an operation involving multiple data types is being performed. For example when an integer and a floar are added, the integer gets promoted to float. Also happends when arguments are passed to functions. 

# Instructions

# Resources

https://www.youtube.com/watch?v=byRw36Y3Hjs&t=854s
Useful walkthoight of the logic behind the project

# Notes

### Library reminders
<stdio.h> 
To use printf
<unistd.h>
To use write function 
<stdlib.h>
To use malloc and free
# include <stdarg.h>

### Hepful commands to debug

`cat file       → dump the whole file`
`head -n 80 file → first 80 lines`
`sed -n '15,25p' file → arbitrary range`

### Quick test
cat << 'EOF' > /tmp/peek.c
#include <stdio.h>
#include <limits.h>
int main(void)
{
    /* %u — unsigned decimal */
    printf("%%u of 0          → [%u]\n", 0);
    printf("%%u of 42         → [%u]\n", 42);
    printf("%%u of -1         → [%u]\n", -1);                /* tricky! */
    printf("%%u of UINT_MAX   → [%u]\n", UINT_MAX);

    /* %x — lowercase hex */
    printf("%%x of 0          → [%x]\n", 0);
    printf("%%x of 10         → [%x]\n", 10);
    printf("%%x of 255        → [%x]\n", 255);
    printf("%%x of 4096       → [%x]\n", 4096);

    /* %X — uppercase hex */
    printf("%%X of 255        → [%X]\n", 255);
    printf("%%X of 4096       → [%X]\n", 4096);

    /* %p — pointer */
    printf("%%p of NULL       → [%p]\n", (void *)0);
    printf("%%p of 0x42       → [%p]\n", (void *)0x42);
    int x = 7;
    printf("%%p of &x         → [%p]\n", (void *)&x);

    return 0;
}
EOF
cc /tmp/peek.c -o /tmp/peek && /tmp/peek




cat << 'EOF' > /tmp/peek.c
#include <stdio.h>
#include <limits.h>
int main(void)
{
    /* %u — unsigned decimal */
    printf("%%u of -1         → [%u]\n", -1);                /* tricky! */
        printf("%%u of -10         → [%u]\n", -10);                /* tricky! */
    printf("%%u of -1000         → [%u]\n", -1000);                /* tricky! */

    printf("%%u of UINT_MAX   → [%u]\n", UINT_MAX);

    return 0;
}
EOF
cc /tmp/peek.c -o /tmp/peek && /tmp/peek

