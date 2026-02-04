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
    buffer_size = 128 << 20; // 128 MB
    buffer = (char*)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(buffer, 'x', buffer_size - 1);
    // Place a null terminator at a random position within the buffer to simulate string length
    // Use a deterministic "random" position based on clock for consistent behavior
    uint64_t seed = (uint64_t)&buffer;
    size_t null_pos = 1 + (seed % (buffer_size - 1));
    buffer[null_pos] = '\0';

    s = buffer;
    len = buffer_size;
    i = 0;
}