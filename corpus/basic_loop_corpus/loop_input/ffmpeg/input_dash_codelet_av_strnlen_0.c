#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(buffer, 'A', buffer_size - 1);
    // Place a null terminator at a random position near the end to simulate string length
    // This ensures the loop stops before reaching the buffer boundary
    size_t null_pos = buffer_size - 1 - (clock() % 1024); // Vary position slightly
    buffer[null_pos] = '\0';

    s = buffer;
    len = buffer_size;
    i = 0;
}