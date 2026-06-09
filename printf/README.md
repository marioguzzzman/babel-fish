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



# Instructions

# Resources

https://www.youtube.com/watch?v=byRw36Y3Hjs&t=854s
Useful walkthoight of the logic behind the project

# Notes

# include <stdio.h> 
To use printf
# include <unistd.h>
To use write function, malloc and free
# include <stdarg.h>

