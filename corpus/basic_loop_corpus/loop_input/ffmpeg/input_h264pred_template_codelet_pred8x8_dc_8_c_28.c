#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
uint8_t *src;

void init_vars() {
    const int width = 8;
    const int height = 8;
    stride = width;
    uint8_t *buffer = calloc(height, width);
    if (!buffer) {
        exit(1);
    }
    src = buffer;

    for (int idx = 0; idx < width * height; idx++) {
        src[idx] = rand() % 256;
    }

    i = 0;
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
}