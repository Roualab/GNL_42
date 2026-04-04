*This project has been created as part of the 42 curriculum by rlabbaou.*

# get_next_line

## Description

get_next_line is a 42 project that implements a function returning one line at a time
from a file descriptor. Each successive call returns the next line, including the
terminating `\n` except at end of file. The project teaches the use of static
variables in C to persist state between function calls.

## Instructions

**Compile:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
BUFFER_SIZE can be any positive integer. The code handles edge cases for very
small (1) and very large (10000000) buffer sizes.

**Usage:**
```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
```

## Algorithm

The implementation splits the work across two functions:

**`read_to_stash`** accumulates raw data from the file descriptor into a persistent
static string (`stash`) using `ft_strjoin`, reading `BUFFER_SIZE` bytes at a time
until a `\n` is found or EOF is reached.

**`get_next_line`** then extracts the first line from the stash, allocates and returns
it, and saves the remainder back into the static variable for the next call.

This approach reads as little as possible per call — it stops reading as soon as a
newline is found in the stash, satisfying the subject's efficiency requirement.
The stash persists between calls via a `static char *`, which retains its value
across invocations without using global variables.

## Resources

- `man 2 read`
- `man 3 malloc` / `man 3 free` — memory management
- https://www.youtube.com/watch?v=8E9siq7apUU&pp=ygUNZ2V0IG5leHQgbGluZQ%3D%3D

**AI usage:** Claude was used to help debug norm errors (TOO_MANY_LINES,
TOO_MANY_VARS_FUNC) and to clarify pointer arithmetic questions during development.
No code was generated directly by Ai.
