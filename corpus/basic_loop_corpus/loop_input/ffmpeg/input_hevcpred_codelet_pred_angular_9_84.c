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

    src = (uint16_t*)aligned_alloc(64, size * size * sizeof(uint16_t));
    ref = (uint16_t*)aligned_alloc(64, (size + 100) * sizeof(uint16_t));

    for (int i = 0; i < size * size; i++) {
        src[i] = 0;
    }
    for (int i = 0; i < size + 100; i++) {
        ref[i] = (uint16_t)(i % 32768);
    }
}