#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

    for (size_t idx = 0; idx < data_size - 1; ++idx) {
        buffer[idx] = 'A'; // non-zero to keep loop condition s[i] true
    }
    buffer[data_size - 1] = 0; // null terminator to break loop

    s = buffer;
    len = data_size;
    i = 0;
}