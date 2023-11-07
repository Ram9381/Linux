#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  
    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[4096];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) == -1) {
            perror("Failed to write to stdout");
            close(fd);
            return 1;
        }
    }

    close(fd);
    return 0;
}

