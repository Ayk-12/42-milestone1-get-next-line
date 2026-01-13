*This project has been created as part of the 42 curriculum by atchelde.*

## Description

**get_next_line** is a C project that aims to implement a function capable of reading a file descriptor **line by line**, returning one line at each call until the end of the file is reached.

The goal of this project is to deepen understanding of:
- File descriptors
- Static variables
- Memory management
- Buffered reading using `read()`

## Instructions

### Compilation

Compile the project with:

```bash
cc -Wall -Wextra -Werror {main file}.c get_next_line.c get_next_line_utils.c
```

An optional *BUFFER_SIZE* flag can be included:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n {main file}.c get_next_line.c get_next_line_utils.c 
```
where *n* is any positive integer.

## Resources

### Technical References

- Linux read() manual
- 42 subject PDF for get_next_line
- GNU C Library documentation
- C standard library references

### Use of AI

AI tools were used only as a learning aid, specifically for:

- Understanding algorithmic approaches
- Clarifying edge cases (EOF handling, buffer behavior)
- Improving documentation clarity
- Pointing out and helping with memory leaks

All code logic, structure, and implementation decisions were written and validated manually.

## Algorithm Overview and Justification

The core idea of the algorithm is to **read chunks of data from a file descriptor and store them until a full line is available**.

### Key Design Choices

- **Static storage** is used to preserve unread data between function calls.
- **Buffered reading** (`BUFFER_SIZE`) minimizes system calls while ensuring flexibility.
- **Dynamic memory allocation** allows handling lines of arbitrary length.
- **Separation of concerns**: utility functions are implemented in `get_next_line_utils.c` to improve clarity and reusability.

### Function Breakdown

#### get_next_line.c

##### char	*get_next_line(int fd)

- Main function of the project.
- Returns the next line read from the given file descriptor.
- Uses a static buffer to store leftover data between calls.
- Returns NULL when there is nothing left to read or on error.

##### char	*ft_readline(int fd, char *buffer, int bytes_read)

- Reads data from the file descriptor into a temporary buffer.
- Appends the read data to stash until a newline is found or EOF is reached.
- Ensures that reading stops as soon as a complete line is available.

##### char	*ft_get_line(char *buffer)

- Extracts and returns the first complete line from stash.
- Includes the newline character (\n) if present.
- Allocates memory dynamically for the returned line.

##### char	*ft_next(char *buffer)

- Removes the extracted line from stash.
- Keeps the remaining unread data for the next call.
- Frees unused memory to prevent leaks.
