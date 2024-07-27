#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./get_next_line/get_next_line.h"

void run_test(const char *filename, const char *expected_output[], int expected_lines) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    char *line;
    int line_count = 0;
    while ((line = get_next_line(fd)) != NULL) {
        if (line_count >= expected_lines) {
            printf("Test failed: More lines read than expected\n");
            free(line);
            break;
        }
        if (strcmp(line, expected_output[line_count]) != 0) {
            printf("Test failed: Line %d does not match expected output\n", line_count + 1);
            printf("Expected: %s\n", expected_output[line_count]);
            printf("Got: %s\n", line);
        }
        free(line);
        line_count++;
    }

    if (line_count != expected_lines) {
        printf("Test failed: Number of lines read (%d) does not match expected (%d)\n", line_count, expected_lines);
    } else {
        printf("Test passed for file: %s\n", filename);
    }

    close(fd);
}

int main(void) {
    const char *expected_newlines[] = {"\n", "\n", "\n", "\n"};

    run_test("newlines.txt", expected_newlines, 4);

    return 0;
}
