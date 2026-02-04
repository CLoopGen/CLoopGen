#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec runtime on modern CPU
    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs through most of the buffer
    memset(internal_buffer, 'x', data_size - 1);
    internal_buffer[data_size - 1] = '\0'; // null terminator to break loop

    s = internal_buffer;
    len = data_size;
    i = 0;
}