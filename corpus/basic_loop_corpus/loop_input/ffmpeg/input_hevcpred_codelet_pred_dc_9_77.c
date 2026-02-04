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
    size = 65536; // Adjusted for ~0.01 sec runtime on modern CPU

    left = (uint16_t*)aligned_alloc(32, size * sizeof(uint16_t));
    top = (uint16_t*)aligned_alloc(32, size * sizeof(uint16_t));

    for (int idx = 0; idx < size; idx++) {
        left[idx] = (uint16_t)(idx % 32768);
        top[idx] = (uint16_t)((idx * 3) % 32768);
    }

    dc = 0;
    i = 0;
}