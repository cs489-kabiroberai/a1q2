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

    if (freopen(argv[1], "r", stdin) == NULL) {
        perror("freopen");
        return -1;
    }

    execlp("wc", "wc", "-c", NULL);

    // if we get here, exec failed
    perror("execlp");
    return -1;
}
