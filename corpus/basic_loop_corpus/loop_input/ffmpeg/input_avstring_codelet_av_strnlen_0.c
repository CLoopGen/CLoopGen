#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    memset(internal_buffer, 'x', data_size - 1);
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
}