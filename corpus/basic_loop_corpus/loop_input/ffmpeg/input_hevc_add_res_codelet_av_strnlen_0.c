#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer = NULL;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on typical CPU
    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(internal_buffer, 'A', data_size - 1);
    // Place null terminator near the end to allow long loop execution
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}