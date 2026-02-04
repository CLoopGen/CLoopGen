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
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-null bytes
    memset(buffer, 'A', data_size - 1);
    // Place null terminator near the end to ensure loop runs long but terminates
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}