#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return -1;
    }

    if (fseek(file, 0, SEEK_END)) {
        perror("fseek");
        fclose(file);
        return -1;
    }

    long size = ftell(file);
    if (size == -1) {
        perror("ftell");
        fclose(file);
        return -1;
    }

    fclose(file);

    printf("%ld\n", size);

    return 0;
}
