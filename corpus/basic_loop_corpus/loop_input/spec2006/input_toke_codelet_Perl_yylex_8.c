#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *t;
static char *buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill with whitespace characters to make loop iterate over them
    memset(buffer, ' ', data_size - 1);
    // Place a non-whitespace character at the end to terminate the loop
    buffer[data_size - 1] = 'x';

    t = buffer; // Point t to the beginning of the buffer
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}