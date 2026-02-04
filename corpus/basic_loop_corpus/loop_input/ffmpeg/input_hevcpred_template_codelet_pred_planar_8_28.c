#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int trafo_size;
int x;
int y;
uint8_t *src;
uint8_t *top;
uint8_t *left;
int size;

void init_vars() {
    size = 4096;  // Adjusted to achieve ~0.01 sec runtime (approx 16.7M elements)
    trafo_size = 2;
    stride = size;

    src = (uint8_t*)aligned_alloc(32, size * size * sizeof(uint8_t));
    top = (uint8_t*)aligned_alloc(32, (size + 1) * sizeof(uint8_t));
    left = (uint8_t*)aligned_alloc(32, (size + 1) * sizeof(uint8_t));

    for (int i = 0; i <= size; i++) {
        top[i] = rand() % 256;
        left[i] = rand() % 256;
    }
}