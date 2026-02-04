#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *p;
int tile;
int i;

static char *buffer;
static size_t buffer_size = 1 << 20; // 1MB

void init_vars() {
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size - 1; idx++) {
        buffer[idx] = (rand() % 256 == 255) ? '\xff' : 'A';
    }
    buffer[buffer_size - 1] = '\x00';

    p = buffer;
    tile = 1000;
}