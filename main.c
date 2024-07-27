// #include "./get_next_line/get_next_line.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
    int		fd;
    char	*line;

    if (argc == 1)
    {
        // Reading from standard input
        fd = 0;
    }
    else if (argc == 2)
    {
        // Reading from a file
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            return (1);
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    if (fd != 0)
        close(fd);

	// printf("\n\n-- new line \n");
	// size_t len = ft_strlen("\n");
	// printf("new line len: %zu\n", len);

    return (0);
}
