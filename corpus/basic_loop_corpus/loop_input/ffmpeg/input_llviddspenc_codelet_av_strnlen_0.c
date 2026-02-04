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

    // Fill with non-zero bytes except at the end to trigger loop condition
    memset(buffer, 'A', data_size - 1);
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}