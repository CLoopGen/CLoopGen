#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;

STRLEN len;
char *s;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char*)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with mixed case and non-alphabet characters
    for (size_t i = 0; i < data_size - 1; i++) {
        buffer[i] = 'A' + (i % 64); // Creates a pattern including uppercase, lowercase, and symbols
    }
    buffer[data_size - 1] = '\0'; // Null terminate

    // Setup s and len to traverse the entire buffer except last null byte
    s = buffer;
    len = data_size - 1;
}