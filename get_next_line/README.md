*This project has been created as part of the 42 curriculum by maguzman.*

# Description

Write a function that returns a line read from a file descriptor.
- Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
- Make sure that your function works as expected both when reading a file and when reading from the standard input.

Prototype 
`char *get_next_line(int fd);`

RETURN
- Your function should return the line that was read.
- If there is nothing left to read or if an error occurs, it should return NULL.
- The returned line should include the terminating \n character, except when the end of the file is reached and the file does not end with a \n character.

UNDEFINED BEHAVIOR
- get_next_line() exhibits undefined behavior if the file associated with the file descriptor is modified after the last call, while read() has not yet reached the end of the file.
- get_next_line() also exhibits undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

- add this option to your compiler call: `-D BUFFER_SIZE=n` It will define the buffer size for read().
We must be able to compile this project with and without the `-D BUFFER_SIZE` flag in addition to the usual flags. You may choose any default value you prefer.
- You will compile your code as follows (a buffer size of 42 is used as an example): `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`

-Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?
-Try to read as little as possible each time get_next_line() is called. If you encounter a new line, you have to return the current line.

## Read()

The read system call, implemented as the read() function reads the specified amount of bytes cnt of input into the memory area indicated by buf from the file indicated by the file descriptor fd. A successful read() updates the access time for the file. The read() function is also defined inside the <unistd.h> header file.
Syntax

    `read (fd, buf, cnt);`

Parameters

    fd: file descriptor of the file from which data is to be read.
    buf: buffer to read data from.
    cnt: length of the buffer.

Return Value

    Return number of bytes read on success.
    Return 0 on reaching the end of file.
    Return -1 on error.
    Return -1 on signal interrupt.

buf needs to point to a valid memory location with a length not smaller than the specified size because of overflow. fd should be a valid file descriptor returned from open() to perform the read operation because if fd is NULL then the read should generate an error. cnt is the requested number of bytes read, while the return value is the actual number of bytes read. Also, sometimes read system call should read fewer bytes than cnt.
Example

`#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
​
int main() {
    int fd, sz;
    char* c = (char*)calloc(100, sizeof(char));

    fd = open("foo.txt", O_RDONLY);

    if (fd < 0) {
        perror("r1");
        exit(1);
    }

    sz = read(fd, c, 10);
    printf("called read(% d, c, 10). returned that"
           " %d bytes were read.\n",
           fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: % s\n", c);
    return 0;
}`


Output

    called read(3, c, 10).  returned that 10 bytes were read.
    Those bytes are as follows: 0 0 0 foo.

Suppose that sample.txt consists of the 6 ASCII characters “foobar”. Then what is the output of the following program?

`#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char c;
    int fd1 = open("sample.txt", O_RDONLY, 0);
    int fd2 = open("sample.txt", O_RDONLY, 0);
    read(fd1, &c, 1);
    read(fd2, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}`

Output

    c = f

The descriptors fd1 and fd2 each have their own open file table entry, so each descriptor has its own file position for foobar.txt. Thus, the read from fd2 reads the first byte of foobar.txt, and the output is c = f, not c = o.

# Instructions

# Resources

* on read(): https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
* on #define and other macros: https://www.geeksforgeeks.org/c/cc-preprocessors/
* on static variables: https://www.geeksforgeeks.org/c/static-variables-in-c/
* on memory layout: https://www.geeksforgeeks.org/c/memory-layout-of-c-program/

# Notes 