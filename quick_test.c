
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./src/get_next_line.h"

int	read_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	printf("argc: %d\n", argc);
	if (argc == 1)
	{
		fd = 0;
		exit(1);
	}
	else if (argc == 2)
		fd = read_file(argv);
	else
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (fd != 0)
		close(fd);
	return (0);
}
