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
    size_t data_size = 128 << 20; // 128 MB
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(buffer, 'A', data_size - 1);
    // Place a null terminator at the end to ensure loop stops here
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}