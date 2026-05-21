*This project has been created as part of the 42 curriculum by maguzman.*


## Description 

Create a C library from scratch, containing 43 functions programmed for manipulating strings, memory and lists.

libc fubctions: reimplement 23 functions from libc (with their prototypes and matching behaviour as defined in man page).

Additional functions: develop 11 functions that are either not in libc or behave a little differently from the standard function.

Linked list: Set of 9 functions for list manipulation

### Notes


#### Link List 
Data structures and elements linking each other.
We need a strcuture to hold data and then dinamically allocate memory for each block and then link them. 

They are useful for allocating thousands of data structures, for example whats needed for a neural network.

They are also very quick as it is easier to just direct to different addresses where this data structures are allocated instead of cpying or replacing. 

##### Difference with arrays
Arrays are great at random access througth their indexes, but not practical to insert or delete elements.  

Link lists are made of a long chain of nodes, each node containing 2 parts, data and an address to the next node in line. 

They do not have an index, but each of them contain an address to where the next node is located. They can be anywhere in the memory.

Inserting a node is easy as it takes the previous address and then points to the next one. But searching is mucho longer. 

## Instructions

### Running tests

### Running external tests

#### [War Machine](https://github.com/0x050f/libft-war-machine)

Go to the directory where you cloned, add the correct Path in the config.sh file and run the script

`bash grademe.sh`

You can also test individual functions

`bash grademe.sh ft_atoi`

#### [Libft Unit Test](https://github.com/alelievr/libft-unit-test)

## Resources

#### Memmove
if both are empty we need to NULL
- https://marmota.medium.com/c-language-making-memmove-def8792bb8d5
- https://book-of-gehn.github.io/articles/2024/09/21/Behind-memcpy-memmove.html


Link Lists:
- [Introduction to Link Lists](https://www.youtube.com/watch?v=MCIwn7mY4jY)

Friendly repos: 

- https://github.com/aiamlucas/c-the-universe-and-everything
- https://github.com/vineetme/libft_docs
