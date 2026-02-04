#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint16_t *left;
uint16_t *filtered_left;

void init_vars() {
    size = 64 * 1024 * 1024; // 128MB of data (64M elements * 2 bytes each)

    left = aligned_alloc(32, (size * 2 + 2) * sizeof(uint16_t));
    filtered_left = aligned_alloc(32, (size * 2) * sizeof(uint16_t));

    for (int j = 0; j < size * 2 + 2; j++) {
        left[j] = rand() & 0xFFFF;
    }

    for (int j = 0; j < size * 2; j++) {
        filtered_left[j] = 0;
    }

    i = 2 * size - 2;
}