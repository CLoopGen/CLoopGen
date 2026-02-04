#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *cp;
static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with mixed lowercase and other characters
    for (size_t i = 0; i < data_size - 1; i++) {
        int r = rand() % 100;
        if (r < 26) {
            buffer[i] = 'a' + r;
        } else {
            buffer[i] = 'A' + (r % 32);
        }
    }
    buffer[data_size - 1] = '\0'; // Null-terminate

    cp = buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}