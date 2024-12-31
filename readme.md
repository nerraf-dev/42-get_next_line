# get_next_line

## Description

This project is about creating a function that reads a file line by line.

## Usage

To compile the `get_next_line` function with your project, include the following files:
- `get_next_line.c`
- `get_next_line.h`
- `get_next_line_utils.c`

Compile with:
```sh
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
```

## Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("example.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

## Testing

To test the function, create a text file `example.txt` with some content and run the compiled program.

## Notes

- The buffer size can be adjusted by defining `BUFFER_SIZE` during compilation.
- The function returns a pointer to a string that must be freed by the caller.
- The function returns `NULL` when the end of the file is reached or an error occurs.

