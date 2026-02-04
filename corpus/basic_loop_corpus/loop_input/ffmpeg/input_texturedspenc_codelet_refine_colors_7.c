#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
ptrdiff_t stride;
int x;
int y;
int r;
int g;
int b;

void init_vars() {
    const int width = 4;
    const int height = 256 * 1024 * 1024 / (width * sizeof(uint8_t)); // ~256MB
    stride = width;
    block = aligned_alloc(32, (size_t)(stride * height * sizeof(uint8_t)));
    if (!block) {
        exit(1);
    }
    for (int i = 0; i < stride * height; i++) {
        block[i] = rand() % 256;
    }
    x = 0;
    y = 0;
    r = 0;
    g = 0;
    b = 0;
}