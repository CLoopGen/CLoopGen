#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *type;
static char *buffer;
static size_t buf_size = 1 << 20; // 1MB data size

void init_vars() {
    buffer = (char *)malloc(buf_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with whitespace and non-whitespace characters
    size_t i;
    for (i = 0; i < buf_size - 1; i++) {
        buffer[i] = ' '; // Start with spaces
    }
    buffer[i] = 'x'; // Ensure last character is non-whitespace to stop loop
    buffer[i+1] = '\0';

    type = buffer; // Point type to start of buffer
}