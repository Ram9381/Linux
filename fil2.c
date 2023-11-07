#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    

    const char *source_path = argv[1];
    const char *destination_path = argv[2];

    if (rename(source_path, destination_path) != 0) {
        perror("Failed to move/rename the file");
        return 1;
    }

    printf("File moved/rename successfully.\n");
    
    return 0;
}

