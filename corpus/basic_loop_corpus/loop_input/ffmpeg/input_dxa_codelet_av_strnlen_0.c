#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s_buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    internal_s_buffer = (char *)malloc(data_size);
    if (!internal_s_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs through most of the buffer
    memset(internal_s_buffer, 'x', data_size - 1);
    internal_s_buffer[data_size - 1] = '\0'; // null-terminate at end

    s = internal_s_buffer;
    len = data_size;
    i = 0;
}