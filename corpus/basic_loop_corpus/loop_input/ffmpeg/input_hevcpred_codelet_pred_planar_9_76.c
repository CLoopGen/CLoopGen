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
    size = 4096;  // Adjusted to achieve ~0.01 sec runtime on modern CPU
    trafo_size = 2;
    stride = size;

    src = (uint16_t*)aligned_alloc(64, size * size * sizeof(uint16_t));
    top = (uint16_t*)aligned_alloc(64, (size + 1) * sizeof(uint16_t));
    left = (uint16_t*)aligned_alloc(64, (size + 1) * sizeof(uint16_t));

    for (int i = 0; i <= size; i++) {
        top[i] = rand() & 0xFFFF;
        left[i] = rand() & 0xFFFF;
    }

    for (int i = 0; i < size * size; i++) {
        src[i] = 0;
    }
}