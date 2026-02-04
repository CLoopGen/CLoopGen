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
    size_t data_size = 64 << 20; // 64 MB to target ~0.01 sec on modern CPUs
    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(internal_buffer, 'x', data_size - 1);
    // Null-terminate at the end to trigger loop exit
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}