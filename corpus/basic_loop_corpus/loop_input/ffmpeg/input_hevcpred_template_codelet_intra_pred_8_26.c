#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint8_t *left;
uint8_t *filtered_left;

void init_vars() {
    size = 64 * 1024 * 1024;  // 64 million elements for ~0.01 sec runtime on modern CPU

    left = (uint8_t*)aligned_alloc(32, (size_t)(2 * size));
    filtered_left = (uint8_t*)aligned_alloc(32, (size_t)(2 * size));

    for (int j = 0; j < 2 * size; j++) {
        left[j] = rand() & 0xFF;
    }

    for (int j = 0; j < 2 * size; j++) {
        filtered_left[j] = 0;
    }
}