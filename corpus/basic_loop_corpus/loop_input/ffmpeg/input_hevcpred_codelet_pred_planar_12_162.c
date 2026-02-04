#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int trafo_size;
int x;
int y;
uint16_t *src;
uint16_t *top;
uint16_t *left;
int size;

void init_vars() {
    size = 4096; 
    trafo_size = 1;
    stride = size;

    src = (uint16_t*)aligned_alloc(64, size * size * sizeof(uint16_t));
    top = (uint16_t*)aligned_alloc(64, (size + 1) * sizeof(uint16_t));
    left = (uint16_t*)aligned_alloc(64, (size + 1) * sizeof(uint16_t));

    for (int i = 0; i <= size; i++) {
        top[i] = (uint16_t)(i & 0x3FF);
        left[i] = (uint16_t)((i * 31) & 0x3FF);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            src[j + stride * i] = 0;
        }
    }
}