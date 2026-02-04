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
    buffer = (char*)malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(buffer, 'A', buffer_size - 1);
    // Place a null terminator at the end to ensure loop stops there
    buffer[buffer_size - 1] = '\0';

    s = buffer;
    len = buffer_size;
    i = 0;
}