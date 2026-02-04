#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB to ensure ~0.01 sec runtime on modern CPUs
    internal_buffer = (char*)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes except for a null terminator at the end
    memset(internal_buffer, 'A', data_size - 1);
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}