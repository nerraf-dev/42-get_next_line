#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void read_file(const char* filename) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return;
	}

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
		write(STDOUT_FILENO, buffer, bytes_read);
	}

	if (bytes_read == -1) {
		perror("Error reading file");
	}

	close(fd);
}

int main() {
	const char* filename = "test.txt";
	read_file(filename);
	return 0;
}
