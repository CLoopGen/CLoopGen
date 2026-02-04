#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint16_t *top;
uint16_t *left;
int dc;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(uint16_t);  // ~128MB total for two arrays
    left = (uint16_t*)aligned_alloc(32, size * sizeof(uint16_t));
    top = (uint16_t*)aligned_alloc(32, size * sizeof(uint16_t));

    for (int idx = 0; idx < size; idx++) {
        left[idx] = (uint16_t)(idx & 0xFFFF);
        top[idx] = (uint16_t)((idx * 3) & 0xFFFF);
    }

    i = 0;
    dc = 0;
}