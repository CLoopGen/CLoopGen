#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
int i;
uint16_t ve[23];
uint16_t vo[23];

void init_vars() {
    const size_t data_size = 1 << 20; // ~2MB of input data (1<<19 elements * 2 bytes)
    top = aligned_alloc(64, data_size);
    if (!top) {
        exit(1);
    }

    for (size_t idx = 0; idx < (data_size / sizeof(uint16_t)); idx++) {
        top[idx] = (uint16_t)(idx * 31);
    }

    for (int j = 0; j < 23; j++) {
        ve[j] = 0;
        vo[j] = 0;
    }

    i = 0;
}