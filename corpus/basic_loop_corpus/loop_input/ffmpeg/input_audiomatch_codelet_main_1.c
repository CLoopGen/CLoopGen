#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
int datlen;
int16_t *data;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB to ensure loop takes ~0.01s
    datlen = target_bytes / sizeof(int16_t);
    data = aligned_alloc(32, datlen * sizeof(int16_t));
    
    if (!data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with non-zero values to allow meaningful computation
    for (int j = 0; j < datlen; j++) {
        uint8_t byte0 = rand() & 0xFF;
        uint8_t byte1 = rand() & 0xFF;
        data[j] = byte0 + 256 * byte1;
    }

    i = 0;
}