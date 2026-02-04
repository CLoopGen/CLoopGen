#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *left;
uint8_t *filtered_left;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    left = (uint8_t*)aligned_alloc(32, data_size);
    filtered_left = (uint8_t*)aligned_alloc(32, data_size);

    if (!left || !filtered_left) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        left[idx] = rand() & 0xFF;
    }
}

__attribute__((destructor))
void cleanup() {
    free(left);
    free(filtered_left);
}