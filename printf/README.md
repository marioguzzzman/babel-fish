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

# Instructions

# Resources

https://www.youtube.com/watch?v=byRw36Y3Hjs&t=854s
Useful walkthoight of the logic behind the project

# Notes

# include <stdio.h> 
To use printf
# include <unistd.h>
To use write function 
# include <stdlib.h>
To use malloc and free
# include <stdarg.h>

