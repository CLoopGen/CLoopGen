#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
ptrdiff_t stride;
uint16_t *src;
uint16_t *left;

void init_vars() {
    size = 67108864; // 128 MB of data (67M elements * 2 bytes ≈ 128 MB)
    stride = 1;
    i = 0;

    src = (uint16_t*)aligned_alloc(32, (size + 1) * sizeof(uint16_t));
    left = (uint16_t*)aligned_alloc(32, size * sizeof(uint16_t));

    for (int idx = 0; idx < size + 1; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
    for (int idx = 0; idx < size; idx++) {
        left[idx] = 0;
    }
}