#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buf;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    internal_buf = (char *)malloc(data_size);
    if (!internal_buf) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(internal_buf, 'x', data_size - 1);
    // Null terminate at a random position near the end to ensure loop runs long
    size_t null_pos = data_size - 1 - (rand() % 65536);
    internal_buf[null_pos] = '\0';

    s = internal_buf;
    len = data_size;
    i = 0;
}