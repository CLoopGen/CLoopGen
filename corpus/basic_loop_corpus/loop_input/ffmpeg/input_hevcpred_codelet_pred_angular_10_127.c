#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int size;
int x;
int y;
uint16_t *src;
int angle;
uint16_t *ref;

void init_vars() {
    size = 4096;
    stride = size;
    angle = 16;

    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * size * stride);
    ref = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * (size + 100));

    for (int i = 0; i < size * stride; i++) {
        src[i] = rand() % 65536;
    }
    for (int i = 0; i < size + 100; i++) {
        ref[i] = rand() % 65536;
    }
}