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

void init_vars() {
    // Aim for approximately 0.01 seconds runtime on modern CPU
    // For a simple loop like this, around 64MB to 128MB should suffice
    size_t data_size = 128 * 1024 * 1024; // 128 MB

    buffer = (char *)malloc(data_size);
    if (!buffer) {
        // Fallback to smaller size if needed, but assume it works
        data_size = 64 * 1024 * 1024;
        buffer = (char *)malloc(data_size);
    }

    // Fill most of the buffer with non-zero bytes
    memset(buffer, 'A', data_size - 1);

    // Place a null terminator near the end to stop the loop
    // This ensures s[i] becomes 0 within bounds
    buffer[data_size - 1] = '\0';

    // Assign external pointer and length
    s = buffer;
    len = data_size; // Ensure len is large enough so that i reaches nearly data_size
}