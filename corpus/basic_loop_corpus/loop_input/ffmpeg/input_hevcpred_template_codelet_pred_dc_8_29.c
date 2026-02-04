#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint8_t *top;
uint8_t *left;
int dc;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec on modern CPU

    left = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));
    top = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));

    for (int idx = 0; idx < size; idx++) {
        left[idx] = (uint8_t)(idx % 251);
        top[idx] = (uint8_t)((idx * 3) % 251);
    }

    dc = 0;
    i = 0;
}