#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    buffer = (char *)calloc(data_size, sizeof(char));
    if (!buffer) {
        exit(1);
    }
    // Fill with non-zero except one null at the end to ensure loop runs through most of the buffer
    for (size_t idx = 0; idx < data_size - 1; ++idx) {
        buffer[idx] = 'x';
    }
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}