#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  
    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        perror("Failed to open source file");
        return 1;
    }

    FILE *dest = fopen(destination_file, "wb");
    if (dest == NULL) {
        perror("Failed to open destination file");
        fclose(source);
        return 1;
    }

    int c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, dest);
    }

    fclose(source);
    fclose(dest);

    printf("File copy completed.\n");

    return 0;
}

