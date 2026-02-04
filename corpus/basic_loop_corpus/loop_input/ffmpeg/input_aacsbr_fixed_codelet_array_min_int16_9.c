#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *array;
int nel;
int i;
int min;

void init_vars() {
    nel = 1 << 20; // Approximately 2^20 elements for ~2MB of data (1<<20) * sizeof(int16_t) = ~2MB
    array = (int16_t*)aligned_alloc(32, nel * sizeof(int16_t));
    if (!array) {
        exit(1);
    }

    for (int j = 0; j < nel; j++) {
        array[j] = rand() % 50000 - 25000; // Random values in range [-25000, 24999]
    }

    i = 0;
    min = array[0];
}